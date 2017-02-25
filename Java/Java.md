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