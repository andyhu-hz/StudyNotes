# 随机变量的数字特征   

## 数学期望      


## 方差    


## 协方差    

`Cov(X,Y) = E(XY) - E(X)E(Y)`    
`D(X+Y) = D(X) + D(Y) + 2Cov(X,Y)`    


## 相关系数     
相关系数只能表示两个随机变量的线性关系的强弱。      

相关系数通过除以两个变量的方差开根号，从而消除了量纲。     

相关系数可以理解为两个随机变量都经过标准化变换后的两个新随机变量的协方差。     

`|ρ(XY)| <= 1`

## 矩

矩是更具有一般意义的数字特征        

* k阶原点矩    

设有一个随机变量X，若`E(|X|^k) < +∞,(即保证绝对值的期望存在，且有限)`   
则称`αk = E(X^k),k = 1,2,3...`是X的k阶原点矩。    


* k阶中心矩   

若`E(|X - E(X)|^k) < +∞,(即保证绝对值的期望存在，且有限)`   
则称`βk = E(X - E(X))^k，k = 1,2,3...`是X的k阶中心矩。     


介绍完矩的概念，我们可以重新看一下期望和方差，很明显：    

* 期望E(X)就是随机变量X的一阶原点矩    

* 方差D(X)就是随机变量X的一阶中心矩     

同时我们也可以推断出，若高阶矩存在，则低阶矩就存在。     