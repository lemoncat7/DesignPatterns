简单工厂模式是最简单的设计模式之一，其实它并不属于Gof的23种设计模式，
但应用也十分频繁，同时也是其余创建模式的基础，因此有必要先学习简单工厂模式。

客户Jungle需要时可以向工厂提供产品参数，工厂根据产品参数生产对应产品，客户Jungle并不需要关心产品的生产过程细节。

简单工厂模式总结
简单工厂模式的优点在于：
	1 工厂类提供创建具体产品的方法，并包含一定判断逻辑，客户不必参与产品的创建过程；
	2 客户只需要知道对应产品的参数即可，参数一般简单好记，如数字、字符或者字符串等。

但是如果想要添加新的产品  再从抽象类中派生出新的类 需要在 工厂类中再次添加新的分支   明显不符 开闭原则，即添加扩展
	同时又修改了 源码   另一方面  所有判断逻辑在 工厂中实现 一旦 工厂设计出现 故障 则 整个系统都将 影响