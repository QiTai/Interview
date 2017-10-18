### NOTE

+ 当前互联网公司广告、搜索、推荐等都常用的 **LR、FM(Factorization Machine)、GBDT** 等，把原理搞透彻，例如LR的各种优化算法，FM的优化算法，传统GBDT和XGBOOST的原理区别等
+ [机器学习防止过拟合的方法](https://www.zhihu.com/question/59201590)
+ [GBDT与AdaBoost区别](https://www.zhihu.com/question/54626685)
+ [GBDT与XGboost区别]
+ [集成模型GDBT与RandomForest效果好的原因](https://www.zhihu.com/question/51818176)
+ [SVD vs. PCA](https://www.zhihu.com/question/38319536)
  + SVD是PCA的另一种algebraic formulation,这也提供了另外一种算法来计算PCA
+ 为什么逻辑回归的优化目标是最大似然函数而不是均方差？
  + 个人总结：问题是一个二分类问题，y满足伯努利分布，而不是正太分布，可以参考Wikipedia-loss function for classification!
  + 参考[知乎帖](https://www.zhihu.com/question/24900876)
+ 数据不平衡怎么处理？
  + 基本思路：过采样，欠采样
  + 从数据角度 正采样和负采样 从损失函数角度 添加scale平衡数据 从评价角度 用ROC,AUC而不用PRC
+ k-means的目标函数->参考ML Techniques Taipei slides
+ GBDT+LR如何实现广告CTR预估->refer to[Practical Lessons from Predicting Clicks on Ads at Facebook](https://pdfs.semanticscholar.org/daf9/ed5dc6c6bad5367d7fd8561527da30e9b8dd.pdf)
+ Naive Bayes vs. Logistic Regression:
  + The difference between naive Bayes and logistic regression is due only to the fact that the first is generative and the second discriminative; the two classifiers are, for discrete input, identical in all other respects.
  + Naive Bayes is to Logistic Regression what HMM is to CRF, as the following picture shows,
  ![Relationship](Img/HMM-CRF-NB-LR.png)
+ SVM和LR区别
  + [Linear SVM和LR区别](https://www.zhihu.com/question/26768865)
+ [Hadoop实现K-means算法](http://blog.csdn.net/nwpuwyk/article/details/29564249)
+ [频率学派和贝叶斯学派有什么不同？](https://www.zhihu.com/question/20587681)
+ [如何理解95%置信区间](https://www.zhihu.com/question/26419030)
+ [详细解析损失函数正则化与贝叶斯方法的因缘](https://zhuanlan.zhihu.com/p/20620638)
+ [LR为什么要用sigmoid函数](https://www.zhihu.com/question/35322351) [指数族分布与广义线性模型](http://blog.csdn.net/u011467621/article/details/48197943)
+ LR和SVM使用情况
  * 如果Feature的数量很大，跟样本数量差不多，这时候选用LR或者是Linear Kernel的SVM
  * 如果Feature的数量比较小，样本数量一般，不算大也不算小，选用SVM+Gaussian Kernel
  * 如果Feature的数量比较小，而样本数量很多，需要手工添加一些feature变成第一种情况
+ [CTR预估一般采用LR+连续特征离散化,连续特征离散化的作用是什么?](https://www.zhihu.com/question/31989952)
  + LR一般和特征工程紧密联系在一起
  + [对于特征离散化，特征交叉，连续特征离散化非常经典的解释](http://blog.csdn.net/lujiandong1/article/details/52412123)
+ FM[Factorization Machine]
  + [1](https://tech.meituan.com/deep-understanding-of-ffm-principles-and-practices.html#mjx-eqn-eqfm)
  + [2](https://tracholar.github.io/machine-learning/2017/03/10/factorization-machine.html)
+ [推荐算法](https://www.ibm.com/developerworks/cn/web/1103_zhaoct_recommstudy1/index.html)
  + 以上网页讲的很好
  + 基于人口统计学的推荐算法(无冷启动问题,但是基于用户的基本信息对用户进行分类的方法过于粗糙，尤其是对品味要求较高的领域，比如图书，电影和音乐等领域，无法得到很好的推荐效果)
  + 基于内容的推荐算法:用户喜欢和自己关注过的Item在内容上类似的Item,根据物品或内容的元数据，发现物品或内容的相关性，然后基于用户以前的喜好记录推荐给用户相似的物品(因为需要基于用户以往的喜好历史做出推荐，所以对于新用户有“冷启动”的问题)
  + 协同过滤:用户喜欢那些具有相似兴趣的用户喜欢过的商品(方法的核心是基于历史数据，所以对新物品和新用户都有“冷启动”的问题)
    + 基于用户的协同过滤,具体解释参考 https://www.zhihu.com/question/19971859
    + 基于Item的协同过滤算法
    + 基于模型的协同过滤算法
      + SVD
      + MF
  + 混合推荐：加权混合，切换模式混合，分区混合，分层混合
+ [为什么LR要用对数似然，为什么不用平方损失或者差的绝对值之类的损失]（面试官说就是为了得到凸函数）
  - [怎么从通俗意义上理解逻辑回归的损失函数？](https://www.zhihu.com/question/47744216?from=profile_question_card)
+ [为什么一些机器学习模型需要对数据进行归一化](http://www.cnblogs.com/LBSer/p/4440590.html)
  - [处理数据时不进行归一化会有什么影响？归一化的作用是什么？什么时候需要归一化？有哪些归一化的方法？](https://www.zhihu.com/question/20455227)
+ [K-means中的K如何确定?](https://www.zhihu.com/question/29208148/answer/43812335)
+ 如何判断一张图像是否是模糊的
  - 将图像与一个模糊核（点扩散函数）做卷积，然后和原来的图像作对比，如果变化较大，说明原来图像是清晰的。
+ Random Forest和SVM的使用场景
  - SVM在动辄超高维的文本分类问题中特别受欢迎，可惜内存消耗大，难以解释，运行和调参也有些烦人。而随机森林却刚好避开了这些缺点，比较实用
+ [宏平均和微平均区别](http://blog.csdn.net/u012856866/article/details/52701857)
+ 一般二分类的问题用什么评价指标呢？
  + 分类准确率，但是样本不均衡的情况，很不准确。因此用查准率和查全率
+ 样本不均衡问题，如何解决？
  + 主要三个方面，数据，模型和评估方法。数据上重采样和欠采样，使之均衡；模型上选对样本不均衡问题不敏感的模型，如决策树，不能用KNN；评估方法，用查全率，查准率之类
+ 经常会对连续型特征进行离散化处理，比如年龄分70后，80后，90后，在模型是LR或SVM的情况下，会有什么受益？(可参考[对于特征离散化，特征交叉，连续特征离散化非常经典的解释](http://blog.csdn.net/lujiandong1/article/details/52412123))
+ [如何处理数据缺失问题](https://www.zhihu.com/question/26639110)
+ [机器学习中，有哪些特征选择的工程方法](https://www.zhihu.com/question/28641663)
+ PCA和LDA有很多的相似点，其本质是要将原始的样本映射到维度更低的样本空间中，但是PCA和LDA的映射目标不一样：PCA是为了让映射后的样本具有最大的发散性；而LDA是为了让映射后的样本有最好的分类性能。所以说PCA是一种无监督的降维方法，而LDA是一种有监督的降维方法。
+ [Kd-tree](http://www.cnblogs.com/eyeszjwang/articles/2429382.html)
+ [决策树是如何处理不完整数据的](https://www.zhihu.com/question/34867991/answer/224122110)
+ 特征工程有哪些方法(数据处理上的)主要是统计意义上的一些操作:1.OneHotEncoding 2.标准化 3.归一化 4.连续特征离散化 5.L1正则 6.GBDT 特征组合 7.特征重要性分析方法 卡方检验
+ 网易的面试官透露，社招会比校招容易进很多，尤其是在12月份。因为大家都在等年终奖。还有网易似乎Xgboost和GBDT用的比较多。想进网易的同学，做几个Xgboost和GBDT相关的项目，学一下hadoop或者Spark，至少自己搭个环境，这样进网易比较容易。
+ [异常检测](https://zhuanlan.zhihu.com/p/25753926)
  + [基于统计的方法](https://mp.weixin.qq.com/s?__biz=MzIzODExMDE5MA==&mid=2694182460&idx=1&sn=a4842775394946bb643006e2e7c67be9#rd)
  + [基于矩阵分解](https://mp.weixin.qq.com/s?__biz=MzIzODExMDE5MA==&mid=2694182465&idx=1&sn=c644809b757bb1c3f0439eae4bb2f78c#rd)
  + [Replicator Neural Networks (RNNs)](https://mp.weixin.qq.com/s?__biz=MzIzODExMDE5MA==&mid=2694182516&idx=1&sn=057cdf801d322da4d83dbf96376e7eee#rd)
  + [异常点检测算法综述](https://mp.weixin.qq.com/s?__biz=MzIzODExMDE5MA==&mid=2694182558&idx=1&sn=7a9043417ceaf3ca783a507eea18c2d6&chksm=cc5f021ffb288b095834570b123ad9c5d4e36e852f9f5bc4fea738486e3577dde69fa9b9b43f#rd)
+ [L1比L2更易获得稀疏解](https://www.zhihu.com/question/37096933)
  + L1可以近似L0,而L0是直接冲着稀疏解去优化的
  + l2 regularisation 相当于假设我们所求解w的分布为高斯分布，l1对应的先验概率函数则为拉布拉斯分布，是稀疏的
  + 画周志华书上的那副图
+ [正则化为什么可以起到防止过拟合的作用](https://www.zhihu.com/question/20700829)
  + 正则化在某种意义上来讲引入了参数的先验分布，减少参数的选择空间，放到广义线性模型中，就是对一些基函数作了取舍
  + 对于少数据量的情形，越简单的模型，越不容易过拟合，正则化趋向于让参数小，而这意味着模型简单

### TODO
+ xgboost
  + xgboost里面的lambda rank的损失函数是什么？
  + xgboost在什么地方做的剪枝，怎么做的？
  + xgboost如何分布式？特征分布式和数据分布式?各有什么存在的问题？
  + lightgbm和xgboost有什么区别？他们的loss一样么？ 算法层面有什么区别？
  + lightgbm有哪些实现，各有什么区别？
+ 优化算法
  + 拟牛顿法和牛顿法的关系，拟牛顿法解决了牛顿法哪个问题？推导下牛顿法。牛顿法在什么时候只需要迭代一次就能求解，什么时候牛顿法不能适用？
  
#### 场景题
+ 需要根据用户的query来设计一个广告投放系统，怎么设计，具体到模型设计细节。输入query要能输出广告的一个rank。中间涉及pairwise版模型的设计，以及sentence embedding的设计细节？
+ 给定（用户id，时间，经度，纬度）四元祖，设计方案识别用户家和公司的位置。这题个人觉得是很好的面试设计题，我的方法是密度聚类定地点位置，时间段活跃特征＋是否工作日训练分类模型识别家/公司的方法？
+ 在电商或游戏行业有许多优质用户，如何利用百度的数据帮他们找出其他的优质用户，需要在各个行业有通用性，假设其他行业的用户与百度的用户id是有一对一映射的。说到采样负样本（优质用户id作为正样本）并进行模型训练的方法，开始问如何解决多次训练耗时较长，并且需要预测几亿用户耗时的问题？
+ 在商品批发中（1688）会有客户进行商品报价的询问，但有时会有一些垃圾询问、友商间谍套价等非正常询问，如何设计算法排查此类情况？