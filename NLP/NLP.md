### 面试题

#### https://www.nowcoder.com/discuss/36815?type=0&order=0&pos=46&page=2
+ 商品的标题有几十个字符，怎么得到和某个商品最相似的K个商品？（先分词再用词嵌入，平均之后拿这个向量互相算余弦距离）
+ 得到向量后，如何在几千万甚至上亿个商品内找到前K个最相似的。如何提高效率？（这个是秋招的面试题，当时只答了Kd-Tree相关，工作以后，知道了ANN(相似近邻检索如HNSW)）

+ 在商品批发中（1688）会有客户进行商品报价的询问，但有时会有一些垃圾询问、友商间谍套价等非正常询问，如何设计算法排查此类情况？

+ 简历中若涉及GRU，以下问题被问到：
  + GRU（介绍GRU，什么是更新门以及重置门，重置门接近1那么上一时刻隐藏层几乎完全传递给当前时刻隐藏层，那么当前时刻隐藏层如何跟当前输入关联等）?
  + 输入输出不定长怎么解决的?
  + attention机制?

+ 分词问题有哪些解决办法？词典，crf，lstm，lstm怎么做分词？
+ LSTM(各种门)?


##### About NLP
+ Hidden Markov Model
+ Maximum Entropy Markov Model
+ Conditional Random Field
+ label biased problem
+ [Why is skip-gram better for infrequent words than CBOW?](https://stats.stackexchange.com/questions/180548/why-is-skip-gram-better-for-infrequent-words-than-cbow)
+ tf.idf -> known
+ 词向量 -> known
+ LDA模型 -> todo
