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

### JVM内存
+ 运行时数据区包括：虚拟机栈区，堆区，方法区，本地方法栈，程序计数器
+ 虚拟机栈区 ：也就是我们常说的栈区，线程私有，存放基本类型，对象的引用和 returnAddress ，在编译期间完成分配。
+ 堆区 ， JAVA 堆，也称 GC 堆，所有线程共享，存放对象的实例和数组， JAVA 堆是垃圾收集器管理的主要区域。
+ 方法区 ：**所有线程共享**，存储已被虚拟机加载的类信息，常量，静态变量，即时编译器编译后的代码等数据。这个区域的内存回收目标主要是针对常量池的对象的回收和对类型的卸载。
+ 程序计数器 ：**线程私有**，每个线程都有自己独立的程序计数器，用来指示下一条指令的地址。

### Java String “==”,  “equal"
+ 问：String s1="abc"; s2="abc"； s3= new String("abc")；为啥s1和s2的地址值一样而s1和s3的就不一样呢？也就是，为什么 s1==s2但s1!=s3呢？

+ 答：先是在内存里创建了一个abc字符串，然后s1指向abc，s2要指向abc，内存中已经有abc，所以s1和s2地址相同，s3指向的是新字符串abc的地址，所以s1与s3不同，s1==s2但s1!=s3，因为s1,s2，s3是引用，比较的是地址而不是内容，所以有这个结果，比较值是否相同应该用。equal函数而不能直接用==

### "短路"概念
+ 逻辑运算符：&&和|| 是按照“短路”方式求值的。如果第一个操作数已经能够确
  定表达式的值，第二个操作数就不必计算了
+ 位移运算符：&和| 运算符应用于布尔值，得到的结果也是布尔值，不按“短路”方式计算。即在得到计算结果之前，一定要计算两个操作数的值。



### HashMap/Hashtable/TreeMap

+ HashMap是Hashtable的轻量级实现（非线程安全的实现），他们都完成了Map接口，

  主要区别在于HashMap允许空（null）键值（key）,由于非线程安全，效率上可能高于Hashtable。

  HashMap 把Hashtable的contains方法去掉了，改成containsvalue和containsKey。因为contains方法容易让人引起误解HashMap是Hashtable的轻量级实现（非线程安全的实现），他们都完成了Map接口，

  主要区别在于HashMap允许空（null）键值（key）,由于非线程安全，效率上可能高于Hashtable。

  HashMap 把Hashtable的contains方法去掉了，改成containsvalue和containsKey。因为contains方法容易让人引起误解

+ [HashMap vs. Hashtable](http://javarevisited.blogspot.com/2010/10/difference-between-hashmap-and.html)

+ [how hashmap works in java](http://javarevisited.blogspot.com/2011/02/how-hashmap-works-in-java.html)

+ Hashtable与TreeMap一看SUN国王居然默许了HashMap的冒险行为,使得HashMap家族的利润大大增加,这两个家族也不甘寂寞,于是乎也就允许了自己的键值对可以为"",但是不能触碰null的界限.

+ HashMap实际上是一个“链表散列”的数据结构，即数组和链表的结合体。HashMap的底层结构是一个数组，数组中的每一项是一条链表。 HashMap实现不同步，线程不安全；HashTable线程安全。

+ 解决冲突主要有三种方法：定位法、拉链法、再散列法。HashMap采用的是拉链法解决哈希冲突的。

+ HashMap无序的,LinkedHashMap按照添加顺序存储的,TreeMap可以实现外部排序接口，默认升序

+ Java HashMap  doesn't append the new element at tail instead it append new element at the head *to avoid tail traversing*. If race condition happens then you will end up with an infinite loop.

  Read more: [http://javarevisited.blogspot.com/2011/02/how-hashmap-works-in-java.html#ixzz4abGepUQ9](http://javarevisited.blogspot.com/2011/02/how-hashmap-works-in-java.html#ixzz4abGepUQ9)


### HashMap/TreeMap/LinkedHashMap/HashTable
+ 
  ![Difference](/Img/Difference between HashMap_TreeMap_LinkedHashMap_and_hashtable in Java.png)

### HashMap vs. LinkedHashMap
+ [Differences](http://www.java67.com/2012/08/difference-between-hashmap-and-LinkedHashMap-Java.html)

### ConcurrentHashMap和Hashtable比较

+ [stackoverflow](http://stackoverflow.com/questions/12646404/concurrenthashmap-and-hashtable-in-java)
+ [Java ConcurrentHashMap Best Practices](http://howtodoinjava.com/core-java/collections/best-practices-for-using-concurrenthashmap/)



### Java Collection and Map
+ Collection
  + List
     + LinkedList 非同步
        + ArrayList  非同步，实现了可变大小的元素数组
        + Vector     同步
          + Stack
  + Set   不允许有相同的元素
     + hashSet
       + TreeSet (自动排序)	


+ Map
  + HashTable 同步，实现一个key--value映射的哈希表
    + HashMap    非同步，
    + WeakHashMap 改进的HashMap，实现了“弱引用”，如果一个key不被引用，则被GC回收

+ More as follows:
+ ![Iterable](/Img/Map&Collection.png)

### Iterate over HashMap

```java
Map<String, String> map = new HashMap<String, String>();
for (Iterator it = map.entrySet().iterator(); it.hasNext(); ) {
  Map.Entry entry = (Map.Entry)it.next();
  Object key = entry.getKey();
  Object value = entry.getValue();
}
```

### Collections.sort()及Arrays.sort()底层原理
+ TimSort待深入理解
+ [TimSort原理](http://blog.csdn.net/yangzhongblog/article/details/8184707)




### [Top 25 Java Collection Framework Interview Questions Answers for Freshers and Experienced Programmers](http://javarevisited.blogspot.com/2011/11/collection-interview-questions-answers.html#ixzz4aYLd1P5W) -> **TODO!!!**
### volatile

### sleep vs. wait
+ sleep和wait的区别有：
  + 这两个方法来自不同的类分别是Thread和Object
  + 最主要是sleep方法没有释放锁，而wait方法释放了锁，使得敏感词线程可以使用同步控制块或者方法。
  + wait，notify和notifyAll只能在同步控制方法或者同步控制块里面使用，而sleep可以在
    任何地方使用
  ```java
  synchronized(x){
  x.notify()
  //或者wait()
  }
  ```

+ sleep必须捕获异常，而wait，notify和notifyAll不需要捕获异常

### Miscellany
+ str.substring(beginIndex, endIndex) : with beginIndex included, but endIndex **not included**!!!
+ ArrayList<Integer> al; al.toString() is a useful function for debugging!


### [Java类加载过程](https://www.nowcoder.com/profile/9531731/test/6727674/26108#summary)



### [What is difference between Enumeration and Iterator in Java?](http://javarevisited.blogspot.com/2010/10/what-is-difference-between-enumeration.html#ixzz4aYNwW224) **TODO**



### [133 Core Java Interview Questions Answers From Last 5 Years - The MEGA List](http://javarevisited.blogspot.com/2015/10/133-java-interview-questions-answers-from-last-5-years.html#ixzz4aYQHjlIv) **TODO**
