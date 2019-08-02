package daemon.util.zip;

import java.util.Hashtable;
import java.util.Vector;
import java.util.zip.ZipException;

public class ExtraFieldUtils
{
  private static Hashtable implementations = new Hashtable();

  public static void register(Class c)
  {
    try
    {
      ZipExtraField ze = (ZipExtraField)c.newInstance();
      implementations.put(ze.getHeaderId(), c);
    } catch (ClassCastException cc) {
      throw new RuntimeException(c + " doesn't implement ZipExtraField");
    } catch (InstantiationException ie) {
      throw new RuntimeException(c + " is not a concrete class");
    } catch (IllegalAccessException ie) {
      throw new RuntimeException(c + "'s no-arg constructor is not public");
    }
  }

  public static ZipExtraField createExtraField(ZipShort headerId)
    throws InstantiationException, IllegalAccessException
  {
    Class c = (Class)implementations.get(headerId);
    if (c != null) {
      return (ZipExtraField)c.newInstance();
    }
    UnrecognizedExtraField u = new UnrecognizedExtraField();
    u.setHeaderId(headerId);
    return u;
  }

  public static ZipExtraField[] parse(byte[] data)
    throws ZipException
  {
    Vector v = new Vector();
    int start = 0;
    while (start <= data.length - 4) {
      ZipShort headerId = new ZipShort(data, start);
      int length = new ZipShort(data, start + 2).getValue();
      if (start + 4 + length > data.length) {
        throw new ZipException("data starting at " + start + " is in unknown format");
      }
      try
      {
        ZipExtraField ze = createExtraField(headerId);
        ze.parseFromLocalFileData(data, start + 4, length);
        v.addElement(ze);
      } catch (InstantiationException ie) {
        throw new ZipException(ie.getMessage());
      } catch (IllegalAccessException iae) {
        throw new ZipException(iae.getMessage());
      }
      start += length + 4;
    }
    if (start != data.length) {
      throw new ZipException("data starting at " + start + " is in unknown format");
    }

    ZipExtraField[] result = new ZipExtraField[v.size()];
    v.copyInto(result);
    return result;
  }

  public static byte[] mergeLocalFileDataData(ZipExtraField[] data)
  {
    int sum = 4 * data.length;
    for (int i = 0; i < data.length; ++i) {
      sum += data[i].getLocalFileDataLength().getValue();
    }
    byte[] result = new byte[sum];
    int start = 0;
    for (int i = 0; i < data.length; ++i) {
      System.arraycopy(data[i].getHeaderId().getBytes(), 0, result, start, 2);

      System.arraycopy(data[i].getLocalFileDataLength().getBytes(), 0, result, start + 2, 2);

      byte[] local = data[i].getLocalFileDataData();
      System.arraycopy(local, 0, result, start + 4, local.length);
      start += local.length + 4;
    }
    return result;
  }

  public static byte[] mergeCentralDirectoryData(ZipExtraField[] data)
  {
    int sum = 4 * data.length;
    for (int i = 0; i < data.length; ++i) {
      sum += data[i].getCentralDirectoryLength().getValue();
    }
    byte[] result = new byte[sum];
    int start = 0;
    for (int i = 0; i < data.length; ++i) {
      System.arraycopy(data[i].getHeaderId().getBytes(), 0, result, start, 2);

      System.arraycopy(data[i].getCentralDirectoryLength().getBytes(), 0, result, start + 2, 2);

      byte[] local = data[i].getCentralDirectoryData();
      System.arraycopy(local, 0, result, start + 4, local.length);
      start += local.length + 4;
    }
    return result;
  }

  static
  {
    register(AsiExtraField.class);
    register(JarMarker.class);
  }
}