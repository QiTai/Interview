### NOTE

#### Interview Question: 

##### 基本概念

+ LSTM各个cell的概念(to memorize?)

##### refers to [如果你是面试官，你怎么去判断一个面试者的深度学习水平](https://www.zhihu.com/question/41233373)

+ weights initialization:不同方式，后果及原因 [Ans](https://www.zhihu.com/question/41233373) (paper to read!!!)
  + Lecun_uniform
  + glorot_normal
  + he_normal
  + batch_normal
+ dropout：做法，用处，解释 [Ans](https://www.zhihu.com/question/41233373) (paper to read!!!)
  + 用处: reduce overfitting, a form of model ensemble, reduce co-adaption
+ activation function: [Ans](https://www.zhihu.com/question/41233373) (paper to read!!!)
  + sigmoid/tanh/ReLu/LeakyReLU/PReLU(?)
+ loss: 有哪些方式(to be concluded, refers to cs231n)
  + hinge(?)
  + Cross Entropy
  + MSE
  + K-L散度(?)
+ optimization:有哪些方式，怎么优化，各自好处，解释(to be concluded, referes to cs231n)
+ Batch Normlization: reduce covariate shift
+ 什么样的数据集不适合用深度学习？
  + **数据集太小**，数据样本不足时，深度学习相对其它机器学习算法，没有明显优势。
  + **数据集没有局部相关特性** ，目前深度学习表现比较好的领域主要是图像／语音／自然语言处理等领域，这些领域的一个共性是局部相关性。图像中像素组成物体，语音信号中音位组合成单词，文本数据中单词组合成句子，这些特征元素的组合一旦被打乱，表示的含义同时也被改变。对于没有这样的局部相关性的数据集，不适于使用深度学习算法进行处理。举个例子：预测一个人的健康状况，相关的参数会有年龄、职业、收入、家庭状况等各种元素，将这些元素打乱，并不会影响相关的结果。
+ 造成梯度弥散的原因,推导一下[Ans](https://www.zhihu.com/question/41233373) (参考资料to read!!)
  + 造成梯度消失的一个原因是，许多激活函数将输出值挤压在很小的区间内，在激活函数两端较大范围的定义域内梯度为0。造成学习停止
+ 如何优化模型：加速收敛，避免overfit,提升精度
  + batch size effect
  + learning rate effect
  + weight initialization effect
  + batch normalization
  + drop-out
  + model average
  + fine-tuning
  + data-augmentation
+ 模型设计：给定一个问题，请描述设计算法架构与分析流程
  + Data Preprocess
  + Define Learning Architecture
  + Objective Function Select or Design
  + How to optimize the performance of your deigned model
  + In what condition, DNN/DL might not be a best choice? (small and biased/unbalanced dataset)
+ CNN
  + 1x1 convolution目的: (?)
  + shared weights vs. locally connected layers: (?)
  + 卷积层共享参数的目的: 减少网络参数数量，一个filter只提取一个特征
  + pooling层的作用：实现数据的降维
  + finetune:(?)
  + **CNN最成功的应用是在CV，那为什么NLP和Speech的很多问题也可以用CNN解出来？为什么AlphaGo里也用了CNN？这几个不相关的问题的相似性在哪里？CNN通过什么手段抓住了这个共性？**[Ans](https://www.zhihu.com/question/41233373) (参考资料to read)
  + **为什么很多做人脸的Paper会最后加入一个Local Connected Conv？**[Ans](https://www.zhihu.com/question/41233373) (参考资料to read)
+ 对所有优化问题来说, 有没有可能找到比現在已知算法更好的算法?[Ans](https://www.zhihu.com/question/41233373) (参考资料to read)
  + 没有免费的午餐定理
+ 广义线性模式是怎样被用在深度学习中的? [Ans](https://www.zhihu.com/question/41233373) (参考资料to read)
  + 广义线性模型相对于经典的线性模型(y=wx+b)，核心在于引入了连接函数g(.)，形式变为：y=g−1(wx+b)
  + 深度学习时递归的广义线性模型，神经元的激活函数，即为广义线性模型的链接函数
+ 何为共线性, 跟过拟合有啥关联?[Ans](https://www.zhihu.com/question/41233373) (参考资料to read)
  + 共线性：多变量线性回归时，变量之间由于存在高度相关关系而使回归估计不准确
  + 共线性会造成冗余，导致过拟合
  + 解决方法：排除变量的相关性，加入权重正则
+ 用贝叶斯机率说明dropout的原理
  + **Dropout as a Bayesian Approximation: Insights and Applications**（to read?)
+ **为什么网络够深(Neurons 足够多)的时候，总是可以避开较差Local Optima？**(paper to read??)
  + [The Loss Surfaces of Multilayer Networks](https://zhuanlan.zhihu.com/)
+ 说明如何用支持向量机实现深度学习(列出相关数学公式给他参考) (?)
+ 类别不平衡怎么办(?)


##### refers to [深度学习相关的职位面试时一般会问什么？会问一些传统的机器学习算法吗？](https://www.zhihu.com/question/54308150)

##### refers to [人工智能从业者面试指南](https://mp.weixin.qq.com/s?__biz=MzIzNzY5NDM2Nw==&mid=2247483961&idx=1&sn=007f5ffbaefb6388069f3cba1c9f80bd&chksm=e8c5fec9dfb277df961e5dd99a5161fdb953522ea9d6495e137316cf29f97e2f3c9b1eeec701#rd) (to read?)



##### About NLP

+ tf.idf
+ 词向量
+ LDA模型



























### Resources

#### Videos

+ Google 2016 Summer Deep Learning:[Building Machines that Imagine and Reason: Principles and Applications of Deep Generative Models](http://videolectures.net/deeplearning2016_mohamed_generative_models/)



#### Refer to CodeExamination for more

