### Java Object基本方法

```java
package java.lang;
public class Object {
	private static native void registerNatives();
	static { registerNatives(); }
	public final native Class<?> getClass();
  	public native int hashCode();
  	public boolean equals(Object obj) { return (this == obj); }
 	protected native Object clone() throws CloneNotSupportedException;
  	public String toString() {
     	return getClass().getName() + "@" + Integer.toHexString(hashCode());
  	}
  	public final native void notify();
  	public final void wait() throws InterruptedException {
    	wait(0);
  	}
  	public final native void wait(long timeout) throws InterruptedException;
  	public final void wait(long timeout, int nanos) throws InterruptedException;
    public void finalize() throws Throwable { }
}
```





### StringBuffer vs. String

+ String is immutable, so use String "+" String to realize the concatenation is not efficient; use StringBuffer instead, here is a demo class for StringBuffer.
```java
public class SimpleStringBuffer {
    private char[] buffer;
    private int capacity;
    private int length;
    
    public SimpleStringBuffer() {
        this(16);
    }

    public SimpleStringBuffer(int l) {
        capacity = l;
        buffer = new char[capacity];
        length = 0;
    }

    public synchronized SimpleStringBuffer append(String str) {
        String s = str;
        if (s == null) s = "null";
        if (length + s.length() > capacity) {
            int l = Math.max(length + s.length(), 2 * capacity);
            char[] b = new char[l];
            for (int i = 0; i < length; i++) {
                b[i] = buffer[i];
            }
            buffer = b;
            capacity = l;
        }
        for (int i = 0; i < s.length(); i++) {
            buffer[length++] = s.charAt(i);
        }
        length += s.length();
        return this;
    }

    public String toString() {
        return new String(buffer, 0, length);
    }
}
```


###  Que

+ What's the difference between HashSet and TreeSet?