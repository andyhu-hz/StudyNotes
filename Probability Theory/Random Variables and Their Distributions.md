# Random Variables and Their Distributions   

# 随机变量     

随机变量的定义可以相对于随机事件的定义来理解        

随机事件指的是随机试验的结果，可以看成是一个静态的概念。     

而随机变量可以看作是一个函数，指的是在相同的随机试验的样本空间内，对每一个样本点，有一个实数与之相对应，这样就得到一个定义在样本空间上的一个单值实函数，称为随机变量，可以看成是一个动态的概念。   

所以，随机事件和随机变量是不同的两个概念，但是二者有相同的样本空间，随机变量的定义域是基本事件的全体。       

下面我们主要讨论一维随机变量。      


# 离散型随机变量    

若随机变量X的取值是有限多个或可列无穷多个，则称X为离散型随机变量       

离散型随机分布有以下性质：   

* P|X = xi| = pi >= 0 （i = 1,2...）    
* ΣPi = 1 （当X取有限个值时）    

反过来，任何一个具有以上两条性质的数列|Pi|，都是离散型随机分布律         

## 伯努利模型     
在一定的条件下进行n次重复独立试验，每次试验的结果只有两种：   

`P(A) = P`,`P(A反) = q = 1 - p`    
则称这n次重复独立试验为n重伯努利试验，或者称为伯努利模型       

伯努利概型是概率论最早研究的一种模型，而且具有很广泛的实际意义。   

下面讨论两种基本的伯努利概型    

## 两点分布      

如果独立重复试验只进行了一次，其结果为0和1：`P(1) = p,p(0) = 1 - p = q`   

称为两点分布，也叫伯努利分布。          

## 二项分布      

如果进行n次伯努利试验，有一个事件A出现了X次，则X就是一个二项分布，发生事件A的概率为p，不发生概率为q=1-p，则n次试验中出现k次事件A的概率为：    

`P(X=k)= C(n,k) * p^k * (1-p)^(n-k)`,`k = 0,1,2...n`       

二项分布概率取最大值时，X=m，则称为中心项，m称为最可能成功次数    


* ex:   
N件产品中有M件次品，进行n次有放回的抽查，求共抽到k次次品的概率：    
设事件A为出现次品，则`P(A) = M / N`      
则抽到k次次品的概率为：`P(X=k) = C(n,k) * (M/N)^k * (1 - M/N)^(n-k)`        

二项分布在一些实际的计算中很复杂，为了解决这个问题，有两个解决方法：   

* 极限定理    
* 泊松分布(Poisson)       

## 泊松分布     

泊松分布也是一种相当重要的离散型随机分布，1837年法国Poisson提出.           

设随机变量X的分布律为： `P|X = k| = λ^k/k! * e^-λ`，`k = 0,1,2...`    

其中λ>0，则称X为服从参数为λ的泊松分布。        

有这样一条性质，`Σλ^k/k! * e^-λ = 1`,这个可以通过泰勒级数展开式求得：    

`e^x = Σx^k / k!`     

正是因为有这个性质，泊松分布才满足离散型随机分布的特点。       

* 泊松分布作为二项分布的极限分布      

* 生活中很多现象都满足泊松分布    

* 泊松定理   
在伯努利试验中，以Pn表示事件A出现的概率(Pn与n有关),如果`nPn->λ`,则当`n->∞`时，`P(X = K) = λ^k/k! * e^-λ`      

也就是说二项分布在一定条件下就可以使用泊松分布的公式计算    

一般来说，n很大，p很小，λ = nP大小适中，这时的二项分布就可以近似成泊松分布    


# 分布函数   

上面提到了离散型随机变量，我们使用分布列(律)的方式来描述它的分布，但是如果现在有一个非离散性的随机变量，它的定义域在一个区间内，而且它不能像离散型随机变量那样把所有可能出现的结果一个点一个点的列举出来，所以我们使用分布律来描述这种随机变量的分布是不妥的，所以这里提出分布函数的概念。      

设X是一个随机变量，x为任意实数，有函数：    
`F(x) = P{X <= x}`      
称为随机变量X的分布函数。     

这里可以明显看到，分布函数F(X)的值随着x的变化而变化。     
在几何上，我们可以把P{X <= x}看成是X落在区间(-∞,x]的概率。      

现在我们讨论一下P{x1 < X <= x2},首先我们可以把X的取值范围划分出来：    

`{X <= x2} - P{X <= x1}`,就是-∞到x2区间减去-∞到x1区间。       
再根据上面提出的分布函数的概念：    

`P{x1 < x <= x2} = P{X <= x2} - P{X <= 1} = F(X2) - F(X1)`     

可以看到，分布函数完美的描述了随机变量X的统计规律性。     

* 分布函数的性质       
 * F(X)单调非减，对x1<x2,F(x1)<F(x2)     
 * 分布函数的值域也为[0,1],而且F(-∞) = 0，F(∞) = 1    
 * F(x+0) = F(x)，F(x+0)代表F(x)的右极限，即该函数是右连续的      

我们可以以画图的方式通过离散性随机变量的分布律求出它的分布函数。        


可以看到离散型随机变量的分布函数是阶梯形，有一定的跳跃性。      

# 连续型随机变量及概率密度函数     

设随机变量X的分布函数为F(x),如果存在非负函数f(x),使：    

`F(x) = ∫(-∞,x) f(t)dt    `
则称X为连续型随机变量，f(x)称为X的概率密度函数      

* 概率密度函数的性质   
 * f(x) >= 0   
 * ∫(-∞,∞)f(x)dx = 1  
 * 对于任意的 `x1 <= x2,P{x1 < X <= x2} = ∫(x1,x2)f(x)dx = F(x2) - F(x1)    `
 * 如果f(x)在x点处连续，则F‘(x) = f(x)    
 * 改变密度函数f(x)在个别点处的函数值，不会影响分布函数F(x)   
 * 对于任意的一个点x，连续型随机变量在这个点的概率为0,p{X = x} = ∫(x,x)f(t)dt = 0 (正是因为这条性质，我们可以将概率为0的事件和不可能事件区分开来，也就是说概率为0的事件也有可能发生，这是两个概念)      

我们约定，提到随机变量的分布时，对于离散型的，我们要列出分布律，对于连续型的，我们要写出它的密度函数来描述它的分布     


# 三种常见的连续性随机变量     

## 均匀分布    

若a < b,随机变量X的概率密度函数为：   

`f(x) = {1 / (b - a) | (a <= x <= b)},{0 | 其他}     `  

则称X在[a,b]上服从均匀分布。        

分布函数可以按照各区间根据分布函数和概率密度函数的关系使用积分推导出来    

均匀分布可以表示一种等可能性，比如随机变量X在落在区间[a,b]上等长度的子区间内的概率相等。   

计算机产生的随机数，计算时的舍入误差都服从均匀分布     

## 指数分布   

设随机变量X的概率密度函数为：    

`f(x) = {λe^(-λx) | x > 0},{0 | x <= 0}    `     

其中λ > 0，称X为服从参数为λ的指数分布       

分布函数可以按照各区间根据分布函数和概率密度函数的关系使用积分推导出来      

指数分布还有一个有趣的性质，称为无记忆性，设一个随机变量X在区间[a,b]分布，如果这个随机变量服从指数分布，那在区间前面是否有事件发生与区间后面事件发生的概率没有影响，这就是无记忆性，而且在所有的连续性分布里，只有指数分布有这样的性质。   

也就是因为这条性质，指数分布一般用来描述消耗性产品的寿命。       
