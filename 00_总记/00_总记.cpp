// 00_总记.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	return 0;
}

//绪论:
// 1.除非有很好的理由允许构造函数被用于隐式类型转换，否则构造函数请声明成explicit
// 2.有新对象被定义就是调用的拷贝构造函数，就算是A a = a1;拷贝赋值运算符只用于没有新对象产生的情况
// 3.面向对象:封装、继承、多态

//条款01:
// 1.内置类型通常pass-by-value更高效，用于自定义类型pass-by-reference-to-const更高效
// 2.

//条款02：尽量以const enum inline 替换#define
// 1.string 往往比 char* 合适
// 尽量用const变量替换宏定义，宏定义可能使目标码变大(代码中包含多份常量的值(比如浮点值))
// 并且编译报错的信息(报的错是定义的实际的值，不是你定义的宏)也不好找
// 2.宏是没有作用域的，而class专属常量可以有作用域，为了只有一份，加上static，static const int NumTurns=5; 
// static确保只有一份，写作成员确保作用域，可加private等控制符
// 但之后必须在实现文件里面进行定义（因为是静态变量）：
// const int ClassName::NumTurns;(现在的新编译器通常都可以in-class初值设定(整形的才可以，ints，chars，bools，并且不需要取它的地址(没搞懂)才可以，需要取地址的话还是需要定义一下)
//const static成员和普通成员可以，non-const static成员不行)

// 3.
// 3.尽量以const常量替换#define
// 如：#define ASPECT_RATIO 1.653=>const double Aspect_Ratio=1.653
// 如果编译器不支持Inclass初值设定(用于其他成员比如数组的大小的时候就需要这种用法),可以用enum替代
// enum替代的好处是:如果你不想让别人用指针指向你的整数常量,enum可以实现这个约束并且不会出现内存分配,在这点上enum更像是define。
// 参见01_01
// 4.3.用inline-template函数可以实现对宏的替换，宏定义的函数更晦涩难懂
// 参见01_02
// 5.#include #ifdef 仍然无法被替代

//条款03:多使用const
// 1.const在*左边，被指是常量，const在*右边，指针是常量，两边，都是常量
// 所以const int* a;和int const * a;都是指向常量
// 
// 2.mutable修饰的成员，即使在const成员函数内也可以被修改
// 3.返回const 类型，可以防止一些无意义的客户端错误(自定义数据类型可能被一些无意义的赋值操作，==写成了=,比如(a+b)=c，如果这个表达式用在了if()比较里面就出大问题了)
// 4.const成员函数的作用:(1):使接口容易理解，哪些接口会修改对象哪些不会(2):使得操作const对象成为可能，因为很多地方都是pass-by-reference-to-const
// 5.两个成员函数如果只是常量性不同，可以被重载，const对象会自动调用const版本的函数
// 6.const成员函数里面可以修改static成员以及mutable成员，参见03_01
// 7.如果const和non-const版本代码重复，应该使non-const调用const版本实现。
// 其中也许需要用到两次转型操作，比如: const_cast<char &>(static_cast<const TextBlock&>(*this)[postition])
// static_cast用来加上常量性从而调用const版本，const_cast用来去掉常量性实现non-const想要的操作
// 但反向做法是错误的。
// 8.bitwise-constness(编译器也是这样实施的) 是不能更改对象(所以static成员除外)的任何一个比特，logical-constness意在可以改变其中一些(客户端侦测不出来就可以了)，用mutable修饰(非static成员变量)

//条款04:确保对象在使用前被初始化(原则:确保每一个构造函数都将每一个成员初始化)
// 1.使用成员初值列（member initialization list）进行初始化，这种方式会调用相应的构造函数版本
// 初始化发生在进入构造函数体之前，如果存在多个构造函数，都有自己的初值列，会带来重复的情况下，
// 可以选择将赋值和初始化代价一样的部分封装进一个Private函数来调用，避免重复
// 即使内置内型初始化和拷贝赋值的代价一致，建议也统一成都用初始化
// 初值列里面可以直接()，不带值，代表调用默认初始化
// const和reference必须使用初值列初始化，不能被赋值
// 初值列里初始化的顺序取决于成员在class中的声明顺序，和排列无关
// C++中成员初始化次序总是相同的:base先，derived后，成员变量按照声明顺序初始化
// 2. static对象的析构函数会在main结束时自动调用
// 3.不同编译单元(源文件)的初始化顺序是不明确的，
// 所以使用local-static对象替换non-local-static对象(global)，类似于单例模式
// 函数内的local static对象会在函数被调用期间首次遇上该对象之定义式时被初始化。
//
// 
//条款05:C++编译器默认生成的函数 
// 1.声明一个空类(class A{};),编译器自动生成:(1):默认构造函数(2)拷贝构造(3)默认析构(4)拷贝赋值
// 这些函数只有被调用，才会被编译器创建出来，这些函数都是public且inline的
// 默认构造函数只有自己未显式定义构造函数(包括拷贝构造，如果定义了拷贝构造，也不会自动生成default ctor了)才会生成
// 默认构造函数和析构函数 主要就是调用base classes和non-static 成员变量的构造和析构函数
// 默认的copying函数就将对象的每一个non-static对象拷贝到目标对象，对于自定义类型，会调用该类型的copying函数，对于内置类型，会直接拷贝每一个bits
// 2.当成员内部有ref和const的时候，
// 如果不手动声明拷贝赋值，编译器不会自动生成拷贝赋值，因为这两种情况不允许更改
// 3.如果base class将copy assignment声明为private,那么其derived class无法自动生成（可以自己写）

//条款06：若不想使用编译器自动生成的函数，应该明确拒绝
// 1.将你不希望使用的函数声明为private并且没有实现(STL中iostream就是这样防止拷贝的)
// 2.可以写成继承自一个UnCopyable类，方便,参见06_01
// 
// 
//条款07：为多态基类声明virtual析构函数
// 1.polymorphic(带有多态性质的)base class都应该声明一个virtual析构函数，
// 否则在出现多态性的时候(通过父类指针调用delete)，将会只删除基类部分,出现部分析构
// 2.如果class带任何virtual函数，就应该声明一个virtual析构函数
// 3.如果class不作为base class使用，就不应该有virtual析构函数，virtual函数会使得对象体积变大，并且不再具有移植性(其他语言不具有vptr,虚函数表,比如在More XXX中最后说到的写和C兼容的代码)。
// 4.声明一个纯虚(virtual void xxx()=0)，可以让这个类无法实例化(abstract)
// 5.纯虚析构函数必须有定义体(常常为空)，参见07

//条款08:别在析构函数里抛异常
// 1.如果被析构函数调用的函数可能抛出异常，则应该在析构函数里捕捉(catch)并吞掉(process)，而不是继续让其传播
// 

//条款09:不要在构造函数和析构函数里面调用virtual函数
//1.因为派生的的构造函数执行过程是，先构造父类部分，在构造派生类本身，
// 如果在派生类构造函数里面调用的话，直接就是调用父类的函数了
// 非正式的说法:在base class构造期间，virtual函数不是virtual函数
// 2.析构函数一开始执行，子类部分先被析构，就成了一个基类对象了，此时也会去调用父类的函数
// 3.如果需要在构造函数里面调用某个函数，最好是调用static成员，会先于普通成员初始化

//条款10:令operator=返回 reference to *this
//几乎所有stl里的实现都遵循这个协议。

//条款11:在operator=中处理自我赋值
// 1.如a[i]=a[j],*px=*py，都可能出现自赋值的现象
// 处理例如：if(this==&rhs) return *this;
// 但通常涉及内存分配的还需要考虑异常安全，这时候做法是先备份之前的内容，分配完成之后再delete
// 以及swap-copy技术
// 
//
//条款12:复制对象不要忘记其中任何一个成分
// 自己实现了copying函数的情况下，如果有成份没有复制，编译器是不会发出警告的(这就好像是编译器觉得你不信任它生成的版本，因此对你报复)!
// 1.子类的copying函数里面，不要忘记父类的成员的复制(但这些成员通常是private)，
// 所以正确的做法是子类去调用父类的copying函数来实现复制
// 2.不要让copy constructor去调用copy assignment，反过来也是一样的，
// 正确的做法是实现一个private的Init函数供两个copying函数调用
// 
//
//条款13:以对象管理资源(RAII:Resources Acquisition Is Initialization,资源取得时机便是初始化时机)
// 通常写代码，使用new后delete是不会造成内存泄漏的，但中间如果有其他控制流(如if goto continue break等，以及异常)跳出了当前顺序分支
// 就可能出现不会执行到delete语句的了，就算你现在谨慎的编写程序不会出现上面的错误，但后面别人来维护的时候也许不会注意到这个问题，因此
// 为了确保总是被释放，应该利用C++"析构函数自动调用机制"把资源放进对象中。
// 1.auto_ptr可以利用元素的析构函数进行自动的内存管理，但是不适用于动态数组的管理
// 2.auto_ptr和shared_ptr都是delete,而不是delete []，shared_ptr是一种RCSP(refercence-counting-smart-pointer，引用计数型智慧指针)
// 3.为什么没有针对动态数组的auto_ptr? 因为vector和string总是可以替代动态数组
// 4.工厂类的函数返回指针非常容易引起资源泄露，因为用户很容易忘记delete,因此需要更改，参见条款18

//条款14:在资源管理类中小心copying行为
// 参见14_01

//条款15:在资源管理类中提供队原始资源的访问
// 1.因为许多API要求直接访问原始资源(raw  resources)，因此你的RAII类必须提供一个访问原始资源的方法。
// 2.shared_ptr的get()和auto_ptr的operator *和operator-> 都是类似的做法。
// 3.访问原始资源的做法通常有两种:(1)提供类似get()类型的函数(2)提供隐式转换函数 operator RawPointerType() const {return _rawpointer};
// (1)的使用更麻烦，每个地方都需要调用.get()，(2)的使用更方便，可以直接传入那些API，但是(2)会带来一些隐患，比如 RawPointerType p1 = RAIIObj; //会直接隐式转换过去
//	RAII classes 不是为了封装某物而存在,它是为了确保资源释放会发生而存在的。

//条款16:new 和delete形式要一致
// 1.如果new[] 了一个动态数组但是却只调用了delete ,则可能只有第一个对象调用了析构函数
// 2.其实这个的道理就是,new[n] 的时候两步，第一部先分配内存，然后调用n次构造函数
//						delete[n]的时候先调用n次析构函数，然后再释放内存
// 动态数组的实现中，大多数编译器是使用了一个n在数组最前面，记录了当前数组的大小来实现的
// 3.尽量不要对数组进行typedef,比如 typedef string AddrLines[100]; 但是delete的时候，不知道是数组，就只用了delete
// 因为其实vector和string足以替代所有的数组操作
//
//
//条款17:用独立语句将newed对象置入智能指针
// shared_ptr<T> 的构造函数是explicit的，不能直接从RawPointer隐式转换到它
// 1.对于processWidget(std::shared_ptr<Widget>(new Widget),priority()) 这个调用而言
// std::shared_ptr(new Widget)和priority()的调用不一定谁先谁后，所以如果先new Widget,
// 然后priority()，最后再执行shared_ptr的构造函数,但是priority()函数内部报了异常的话，shared_ptr就没有管理到对象，就内存泄露了
// 2.解决办法就是，把std::shared_ptr(new Widget())单独拿出来作为一行语句(至少C++跨越语句的各项操作是没有重排的自由的)。

//条款18:让接口容易被正确使用，不易被误用
// 1.许多客户端错误可以用导入新类型的方式避免,限制某些取值可以通过"以函数替换对象，表现某个特定月份"来实现,参见18_01
// 2.预防客户错误的另一个方法是，限制类型什么事可做，什么事不可做，比如加上const作为operator*的返回值，能够防止 a*b=c 这种操作。
// 3.另一个一般性准则: "让你的types的行为与内置类型的一直"，因为客户已经对内置类型的操作很熟悉了，你的types如果是相同的表现用起来就会很方便
// 这条准则的主要目的是为了接口的一致性，比如数组的长度叫size(),length(),count()等等。
// 4.任何接口如果<要求用户做某些事情>，就有着"不正确使用"的倾向,比如返回RawPointer的工厂函数，客户也许会忘记delete或者delete超过一次。
// 这时使工厂返回智能指针就先发制人了。
// 除了上面这种错误，还可能设计者提供了自己的"资源释放函数,因为除了delete还有其他的操作"，但是这样一来，客户也许还是会使用delete而忘记使用你提供的
// 资源释放接口，因此给<shared_ptr并且指定一个deleter>或许就成了最好的做法。
// 5.使用shared_ptr还可以避免Cross-DLL problem

//条款19:设计class犹如设计type
// 1.本条款讲了设计一个新class的所有注意事项(需要考虑的问题)
// 1.新type对象应该如何被创建和销毁？ {operator new,operator new[] ...}
// 2.对象的初始化和复制应该有什么样的差别? (copy  constructor 和copy assignment的差别)
// 3.copy ctor还会用于 passed by value
// 4.新类型的合法值?{影响class必须维护的约束条件,以及成员函数必须执行的错误检查，以及异常}
// 5.新类型是否需要配合某个继承体系？ {继承自的话需要考虑基类的virtual,希望被别人继承尤其注意virtual析构函数}
// 6.你的新类型需要什么样的转换? {希望被隐式转换还是显示，explicit ctor 、operator T()}
// 7.你的新type有多一般化? {template}
// 8.{private public 的设置}
// 9.真的需要一个新type吗{是否有现有class 然后用template实现}

//条款20:尽量以pass-by-reference-to-const 替换 pass-by-value
// 1.可以避免构造函数和析构函数的无谓调用
// 2.有const的情况下可以防止对象被改变
// 3.by-reference可防止slicing(对象切割)问题，
// pass by value如果是子类对象传入基类形参的话，会被直接切割成子类对象
// C++编译器底层，reference通常以指针实现出来,(这也是内置类型其实不如用by value传递的原因吧？)
// 4.pass-by-value适用于:内置类型，stl迭代器,函数对象


//条款21:必须返回对象时，千万不要返回reference
// (看到一个引用，就要认为他是一个别名，那么他本来的名字是什么?)
// 1.不要返回local对象的reference或者指针，会出大错
// 在stack上创建的对象压根出了代码块就不存在了
// 在heap上创建的对象如果被你返回了引用，根本没有办法delete
// (有时候因为一些中间情况，比如w = x*y*z，x*y生成的临时对象根本没法获得其指针来delete)
// 2.也不要用static对象的方法来避免多次调用构造函数和析构函数，首先理由是多线程方面的考虑
// 其次是static对象只存在一份，当(if(a*b)==(c*d))这种情况的时候就会出错，始终为真
// 一个static对象的话会带来很多地方的错误
// 这里就要选择承受这点代价（让编译器来为你进行优化,也许会优化掉这种临时对象）
// 

//条款22:把成员变量声明为private
// 1.声明为public或protected都是没有封装性
// 封装性主要跟当其内容改变时可能造成的代码破坏量成反比
// 改变,比如从代码中移除它(如果不封装，需要改变的地方就到处都是，封装了，需要改变的就只有一个接口函数)
// 2.可以让用户在使用的时候，.的时候不用考虑带不带括号(如果全部进行封装了，就全部都带括号)
// 3.使用函数(public成员函数，接口)可以对成员变量的处理有更精确的控制，可以实现只读只写等控制
// 4.使用接口可以对内部的实现进行封装，内部发生变化完全不让客户知道
// 5.使用函数接口还可以队所有可能的实现提供弹性，比如当变量被读写时通知其他对象，可验证class的约束条件及函数的前提和事后状态等等
// 6.public成员被删除时，所有用到它的客户都会被影响，protected的所有derived class都会受影响。很多代码需要重新编写，测试，编写文档，编译等等。

//条款23:尽量以non-member non-friend 函数替换member函数
// 1.推崇封装的原因:能够使被改变的事物只影响有限的客户
// 2.non-member non-friend不会增加能够访问class之内private成员的函数数量，因此也就没有影响封装性
// 3.建议做成一个Unity类，提供静态函数去调用这些member函数，定义于同一个namespace里面
// 4.同一个namespace，包含不同的头文件，针对不同的功能
// 
//条款24:如果需要为某个函数的所有参数(比如两个参数，三个...)进行(隐式)类型转换，那么这个函数必须是non-member
// 令class支持隐式类型转换是个坏主意，但是当建立数值类型的class时有时是合理的
// 1.结论:能够执行隐式类型转换的条件:参数被置于参数列表内时
// 例子: oneHalf.operator*(2) //此时2在列表内，发生隐式转换(假设构造函数不是explicit)
// 但是当2*oneHalf的时候，调用的是2.operator(oneHalf)(编译器也会继续寻找global空间里的operator*(2,oneHalf),不过这里没有)，
// 显然int类型并没有一个从Rational类隐式转换而来的构造函数，就出错了
// 所以最终把这种函数声明为non-member是最好的选择，
// const Rational operator*(const Rational& rhs,const Rational& lhs)//这样两个参数就都可以放在列表里面了
// 2.member函数的反面是non-member而不是friend函数，friend函数会带来太多问题，尽量避免，就像现实中，不是自己人不一定得是朋友
// 比如这里的operator* 其实没必要弄成friend函数，应该去调用Rational的public接口来实现。

// 
//条款25:swap函数的高效率版本
// 1.当swap缺省版本效率不高的时候（内部含有指针或者大量数据），提供一个public成员函数
// 让其高效的交换你的类型的两个对象(内部调用std::swap只交换你想要的部分)
// 2.在你的class或template所在命名空间提供一个non-member的swap调用你写的成员函数
// 3.为你的class特性化std::swap,(class templates就不要特例化了，不能通过编译)
// 4.确保调用swap的时候包含一个using std::swap，保证调用最优版本的swap


//条款26:尽可能延后变量定义式出现的时间
// 1.当出现前面报错，直接return或者报异常被中断的操作，应该尽量延后定义，来避免构造函数调用的代价
// 2.尽量在确定知道要用一个变量的时候才定义，避免出现先调用默认构造函数，再赋值，
// 而是直接调用有参构造函数赋有意义的初值
// 3.循环的情况下，除非你知道"赋值"成本比"构造+析构"低，那么应该将定义写在循环内部 
// 

//条款27:尽量少做转型操作 (More EffectiveC++ M3.2)
// 1.static_cast类似于旧式转型，但是不能去除常量性(只是不能去除底层const，顶层和普通的const是可以去除的)
// 2.const_cast，用于移除常量性(可以移除所有的const,包括底层const)
// 3.dynamic_cast实现向下安全转型，由父类指针向下转型
// 4.reinterpret_cast实现低级转型，比如pointer to int 转 int或者int*直接转换成char *,转换后是很危险的
// 5.以上四个，除了dynamic_cast旧式操作无法实现(也可以转，只是不检测是否可以正确的转型)
// 旧式操作都可以实现
// 6.注重效率的代码不要有dynamic_cast,用到了RTTI(Runtime Type Information)
// 7.尽量将类型转换隐藏起来不让用户看到
// 8.新式转型各有各的职能且容易辨识，建议使用新式转型。
// 参见Test_Cpps 41

//条款28:避免返回handles指向对象内部成分
// 如果让成员函数返回了指向内部的handle
// (1)破坏访问性，比如虽然是const 成员函数，但是返回了一个非const引用，客户拿到引用后，可以对const对象进行修改了
// (2)出现dangling handles(悬空号码牌)，比如const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft())
// 虽然boundingBox返回了一个const对象by value,之后通过upperleft拿到这个temp对象的左上角的引用再取地址
// 但是问题在于随着作用域的结束，temp对象会析构，之后pUpperLeft拿到的就是一个野指针了。
// 1.避免返回指向对象内部的reference,pointer,iterator等等
// 2.成员函数如果返回成员的引用，最好是const的，这样才不会使访问控制修饰符失效
// 3.有时候还是必须这样做，比如string的operator[]

//条款29:为"异常安全"而努力是值得的
// 1.当异常被抛出时:带有异常安全性的函数会:
//	不泄露任何资源，不允许数据破坏
// 2.异常安全含函数提供一下三个保证之一:
//	基本承诺:如果异常被抛出，程序内的任何事物仍然保持在有效状态下，没有数据会被破坏
//	强烈保证:如果异常被抛出，程序状态不发生改变，如果函数成功就是完全成功，如果函数失败就会恢复到调用函数之前的状态。
//	不抛掷保证:承诺绝对不抛出异常，比如各种内置类型的各种操作都提供nothrow保证。
// 3.对于不具有异常安全性的代码进行修改使之具有基本的异常安全性通常用两步:
//	(1) 使用对象管理资源(比如智能指针，可以防止资源泄露)
//	(2) 调整语句顺序，(原则:不要为了表示某件事情发生而改变对象状态，除非那件事情真的发生了。)
// 4.一个一般化的设计策略可以实现 强烈保证的异常安全性:copy and swap
//	为你打算修改的对象做出一份副本，然后在那份副本上执行一切必要的修改，若有任何修改动作抛出异常，则原对象状态都没有发生改变
//	待所有操作都成功后，再交换副本和原对象，用一个不抛出异常的swap来进行。
// 5.异常安全性取决于所有部分中最差的那一部分，因此系统中有一个不具有异常安全性的函数，这个系统就不具备异常安全性。
// 6.强烈异常安全性保证通常需要提供额外的时间和空间，因此需要视情况而定。

//条款30:inline函数
// 1.inline适用于小型，被调用频繁的函数身上，太大的函数目标码太大，会降低高速缓存命中率
// 2.过度热衷inline会使程序体积庞大(inline就是在编译的时候，用函数体代替函数名(C#的CLI例外，是在运行时))
// 3.编译器会拒绝(但是你仍然可以声明为inline,只是编译器不予理睬)太过于复杂的(带循环或者递归的)函数，以及所有的virtual函数
// 因为virtual是动态绑定，编译器在编译的时候根本不知道调用哪个函数
// 4.函数指针的inline不一定起作用
// 5.inline函数缺点是，一旦函数被改变，所有用到此函数的程序都必须重新编译
// 如果不是inline的话，直接重新连接即好
// 

//31.将文件间的编译依存关系降到最低(其实就是.NET在学的降低不同层之间的耦合，通过接口)
// 1.当修改一个类的实现部分(private成份)的时候，所有包含了这个class的文件都必须重新编译。但是如果是接口修改则不需要。
// 2.不应该手动声明标准程序库，比如string，因为这个类其实不是class 是template，因此声明式其实很复杂，好的做法是直接去包含fwd的头文件。
// 3.当使用一个对象的定义式的时候(Person p)，就需要这个对象的定义，因为这时编译器需要知道person占多大位置。
//	但是如果是指针，就都是4个字节。(这也是java里面引用类型的实现方式,C++的引用底层也是指针，因此类似)
// 4.将实现隐藏于一个指针背后，是常用的做法，使用PersonImpl类来放置实现部分，Person类只提供接口。这样就可以做到接口与实现分离.
// 5.能够使用refercence和pointer的时候就不要使用objects,尽量用声明替换定义,就算是函数的参数用by value传入也可以(返回值也是一样，只需要客户端代码先曝光了对应的定义式即可)
// 6.#include <iosfwd>，这种xxxfwd的头文件里面只包含声明式
// 7.export关键字可以把template定义式和template实现式分开，但目前支持这个的编译器很少。
// 8.接口类(使用implementation的类)被称为handler classes
// 9.制作handle classes的第二种方法是使之成为abstract base class(Interface classes,就是java里面的interface了其实)
//	要使Interface classes能够实例化，可以采用在这个接口内定义一个static的工厂性质的create方法返回这个接口的指针
// ，后面再根据实现这个接口的derived class动态返回所需要对象
// 10.使用impl这种实现，性能会受损失的，每次都必须通过implementation pointer取得对象数据并且还会承受动态内存分配的开销以及bad_allloc的异常性。

//32.public继承一定要是is-a的关系
// 1.public主张继承，能够实施于base class对象身上的每件事情都能实施于derived class身上，反之不行(这也是(ISP)Liskov Substitution Principle,里式替换原则)
// 2.class之间的关系:is-a has-a is-implemented-in-terms-of
// 

//33.避免隐藏继承而来的名称
// 1.详情参见Test_Cpps_26_01
// 2.如果正在使用public继承却有不继承那些重载函数(隐藏了)，就是违背了is-a的关系
// 3.使用using Base::func()或者转交函数可以实现访问被屏蔽的父类函数

//34.non-virtual pure-virtual impure virtual
// 1.pure virtual是希望子类必须重新实现自己的版本（接口继承）
// 2.impure virtual是希望子类接口继承并且有缺省版本
// 3.non-virtual是希望子类不要去改写，就直接用父类的版本（non-virtual成员函数所表现的是一种不变性(invariant)，凌驾于其特异性(specialization)之上的）
// 4.pure virtual父类也可以写实现代码，调用的时候Derived->Base::func(),析构函数例外，是一定会被调用的，所以析构函数就算是纯虚也必须要有定义。

//35.考虑virtual函数以外的其他选择
// 1.NVI(Non-Virtual Interface): public non-virtual成员函数调用private virtual函数实现
// 这个方法也是Tmplate Method设计模式的一种表现形式，NVI的优点在于可以对内部的virtual函数调用前和调用后增加一些操作
// 例如在调用前设定好场景，调用后清理场景。
// 2.使用function pointers 实现strategy模式，每个人物的构造函数指向一个特定函数
// 这个方法的优点是同一类型的不同实体之间可以有不同的健康计算函数并且运行期可以变更只需要提供一个setxxx就行
// 3.使用function<>模板实现，和指针类似，优点是更加灵活，只需要传入兼容类型(返回值或参数可以隐式转换)的函数即可(上面用指针的方法需要完全一致)
// 并且借用bind等方法，可以实现参数数目不同的兼容
// 4.传统strategy模式，需要什么方法，就继承一个derived class即可。
// 5.但是以上几种(除了NVI)替换方式，带来的缺点是，无法访问class的non-public成员。

//36.不要重新定义继承来的non-virtual函数
// 1.如果重新定义继承来的non-virtual函数的话，直观表现是
// 对同一个对象会出现同一函数调用的时候因为不同的指针调用没有多态性，而出现不同的行为(比如对于同一个对象，用自己类的指针和其父类的指针进行调用，将是不同的行为)
// 2.更主要的是在理论层面，non-virtual函数体现的是一种不变性，凌驾于其特异性之上，
// 如果直接non-virtual函数给改写了，这样违背了public继承的is-a的关系

//37.绝不重新定义继承而来的缺省参数值(只考虑带有缺省参数的virtual函数这种情况)
// 1.virtual函数是动态绑定，而缺省参数则是静态绑定的
// 所以:Base *p = new Derived(); 这种情况下，调用
// p->VirtualFunction() , 函数是调用了子类的，但是缺省参数还是用的父类的
// 2.就算是子类和父类的缺省参数相同也不要再重新写一次，第一是代码重复，
// 第二是一旦父类改变，所有子类也得去变(才能保持一致)，耦合性太强


//38.Model has-a or is-implemented-in-terms-of through composition
// 1.public 继承代表is-a，而组合意味着has-a或者is-implemented-in-terms-of
// 2.has-a在应用域出现，is-implemented-in-terms-of发生于实现域
// 标准库的set由平衡查找树实现，每个元素有三个指针，所以如果你的程序空间比速度更重要，需要自己实现一个set而不是用组合或继承去实现
// 3.详情可看用STL的list来实现Set的做法,38_01
// 4.不能根据list用public 继承来实现set，因为public 继承要求is a,但是list能够做的事set却不能。


//派生类与基类的类型转换(来自c++primer15.2.3)
// 1.自动类型转换只对指针或者引用类型有效(多态的时候)
// 2.其他情况下，将一个派生类对象赋值给一个基类对象或者用来初始化基类对象，都是调用的基类里面定义的
// copying函数，故只处理了基类部分的成员。但是这里最后的效果看上去就像是执行了类型转换

//派生访问说明符的作用(来自c++primer15.5)
// 1.派生访问说明符的目的是控制"派生类用户(包括派生类的派生类)"对于基类成员的访问权限
// 并不影响"派生类的成员(本身)或友元"对于基类的访问，这个访问<只取决于基类成员的访问说明符>
// 2.派生访问说明符还控制继承自派生类的新类的访问权限，比如如果一个成员int m1基类里面是public,但是是private继承，
// 则在此派生类里面,m1是private的(但是仍然不影响派生类去访问这个成员，在类内),那么理所应当的，派生类的用户和派生类的派生类
// 就无法访问m1了

//39.private继承的使用
// 1.private继承的时候，子类对象是无法转型成父类的,(包括指针的隐式转型也是一样)，不是is-a的关系了，参见39_01
// 2.private继承而来的父类的所有成员在子类中都是private的，无论之前是public or protected
// 3.private继承只意味着希望使用父类中的实现(通常是为了复用代码)，接口部分被抛弃(全是private)
// 只是为了使用父类中“已经备妥的某些特性”,而不是因为子类和父类有什么观念上的关系(比如public的is a关系)
// 4.private继承意味着is-implemented-in-terms-of，但是能使用复合的时候使用复合，不要使用private继承
// 5.当需要希望继承自此类的derived class 不能改写某个函数的时候(因为子类始终可以覆写或隐藏)，
// 这时，可以通过把这个函数封装在一个private成员里面，子类就无法访问了,也就无法修改了
// 这种复合的使用还可以将文件间的编译依存性降到最低,因为没有单独的头文件存在，而是封装在了一个头文件里面
// 6.private继承还可以用在EBO(empty base optimization，空白基类最优化)中
// 因为一个空类型总是占一个字节(编译器默认分配一个char通常)，但是当这个空白类被用于组合的时候，
// 由于前面可能有int或者其他类型的数据，最终内存对齐就不止占一个字节了，造成浪费，这时可以采用
// private继承，就可以保证只占一个字节,并且也还是能够实现所需要的组合功能,参见39_02
// 7.private继承用于 当derived class 需要访问protected base class的成员或者需要重新定义继承而来的virtual函数时会有用。参见39_03

//40.多重继承的使用
// 1.尽量不要使用多重继承，会导致歧义以及对virtual继承的需要
// 2.多重继承的使用通常是: public 继承自一个接口实现接口继承，
//  再private继承自某class来拿到一些有用的实现来帮助实现接口。

//41.隐式接口和编译期多态
// 1.编译期多态(泛型)和运行期多态(继承)两种多态分别是:哪一个重载函数应该调用、哪一个virtual函数应该被绑定
// 2.参见41_01,给人一种像是在用脚本语言的感觉
// 3.对(clasees，就是非templates)而言接口是显式的，多态是通过virtual发生于运行期。
// 4.对templates而言接口是隐式的，奠基于有效表达式，多台则是通过<template具现化和重载函数解析>发生于编译期

//42.typename和class的区别
// 1.使用template参数的时候，没有任何区别
// 2.当标识嵌套从属类别(出现的情况比如:
// template <typename T>
// void Print2End(typename const C::const_iterator iter) //这个地方无从得知C::const_iterator到底是C内部的类型还是一个静态成员变量了(都是通过::来访问)，并且C++默认是不把它当做嵌套从属类型的，因此需要加上typename
// {
// 	typename C::const_iterator end; 
// }
//)的时候，必须加typename,才能判断是类别，而不是其静态成员或者是某个全局变量
// 因为再加一个typename就太长了，因此还经常用在typedef的时候,比如:
//typedef typename std::iterator_traits<IterTY>::value_type value_type;
// 参见42，VS可以不用

//43.如何处理模板化基类里的名称
// 1.当一个子类继承自模板化基类的时候，是不能直接"不加修饰"直接调用模板化基类里的函数的
// 因为base class templates可能被特化，而特化版本可能不提供和这个template相同的接口
// 2.解决方法是:(1)调用的时候加上this->basefunc()(2)使用using Base<T>::basefunc()
// (3)指明函数位于父类里面，Base<T>::basefunc();
// 参见43_01(VS里面貌似不用这样做了，直接动态帮你确定了已经。。)

//44.非类型模板参数往往会造成代码膨胀
// 1.模板也可以有非类型的参数，参见44_01
// 2.但是非类型的模板参数会导致代码膨胀，针对每个非类型参数都会产生一份新的二进制码
// 3.通常这种非类型的参数尽量用成员变量代替
// 4.类型模板参数也可能会造成代码膨胀，比如int和long其实是一份实现，(我相信VS是做了的)
// 5.非类型模板参数带来的代码膨胀，通常都可以由函数参数或者class成员变量替换template参数。


//45.成员函数模板可以用来接受所有兼容类型
// 1.智能指针或者自己写的类型如果想实现像传统的普通指针一样支持隐式类型转换的话，可以运用成员模板来实现一个class 生成函数(泛化copy ctor)
// 具体看45_01的例子
// 2.泛化的copy构造函数和assignment不影响普通的(声明了泛化版本不声明普通版本，编译器还是会帮你生成)，必须同时定义

//46. 需要类型转换时请为模板定义非成员函数
// 1.当条款24的rational类变成tempaltes的时候，外部的operator*也跟着变成template function，但是此时混合相乘，比如oneHalf * 1 却不能编译通过
// 因为传递给operator*的第二实参是 int类型， template实参推导过程中不会出现先从int隐式转换到rational<int>的过程，再从Rational<int>推导出T是int
// 这时可以利用将这个operator*的模板函数声明为friend来解决，因为friend函数在类内直接就被提前声明了，所以能够成功调用。
// 2.在类内声明并且写函数体，会默认成为inline函数，要避免目标码太大的话，可以通过调用外部的辅助函数来实现。

//47. 使用trait classes 表现类型信息
// 1.stl的迭代器有五类:
//	input output forward bidirectional RandomAccess
// input output是单向只能向前并且只能一次一步，只能read or write
// forward 可读可写，一次一步，=input+output
// bidirectional 相当于 forward+向后移动
// random 相当于bidirectional+移动n步
// 2.traits_classes 使得类型相关信息在编译期可用
// 3.实现编译期间的if else 可用函数重载来实现
// 具体实现参考47_01

//48. template元编程(template metaprogramming)
// 1.TMP编程是用C++写成、执行于C++编译器内部的程序，它的输出就是从templates里面具现化出的代码
// 2.TMP两个伟大贡献:
//	(1)它让某些事情变得容易
//  (2)将一些工作从运行期转移到编译期，使得错误可以在编译期提前发现，可执行文件边小，内存需求变少，但是编译时间变长。
// 3.TMP是图灵完备语言，但是语法不同，比如用重载实现if else,递归实现循环，TMP是个函数式语言

//49. 了解new-handler的行为
// 参考49_01
// 找到目前使用的new_handler 可以用 new_handler old = set_new_handler(NULL);来实现

//50. 了解new和delete的合理替换时机
// 1.什么时候会想自己来替换编译器提供的operator new和operator delete呢？
// (1)用来检测运用上的错误。当出现overturns(写入到了分配区尾端之后)或underturns(之前)的情况下
//		如果自定义一个operator news,便可以分配超额内存空间，用额外的空间充当"哨兵"配合和自定义的operator deletes实现检测
// (2)获得效能提升。主要就是连续分配内存的时候，有大有小可能出现破碎问题，自定义的版本可以更加合理的利用破碎空间。
// (3)收集使用上的统计数据。简单的说就是可以log，用来调试等等。
// 参见50_01
// 2.其他的用处:
// (1)增加分配和归还速度(2)降低缺省内存管理器带来的空间额外开销(3)弥补缺省分配器中的非最佳对齐(4)将相关对象成簇集中(5)获得非传统行为。

//51. 编写new和delete的时候需要遵守规范
// 1.operator new 应该包含一个无穷循环，在其中尝试分配内存，如果不能满足要求则调用new_handler，并且还需要处理比正确大小更大的错误(子类来调用继承的版本)
// 2.operator delete应该在收到null的时候什么都不做，也需要处理继承的版本。

//52:placement new和placement delete
// 1.正常形式的operator new和operator delete只包含一个参数,new(size_t),delete(void *rawMemory)
// 2.如果在正常形式的基础上还有其他参数则是placement new和placement delete(这里说的是广义的placement xxx，其实一般来说Placement xxx都是特指:
//void * operator new(size_t size, void * p) throw(); //
//)
// 3.placement new和placement delete必须形式上对应，delete的时候是调用的正常形式的delete，只有当报new一个对象的时候，两步，第一步分配内存如果成功
// 第二部构造对象如果失败，就会调用对应形式的operator delete,否则找不到对应形式的话就会直接内存泄漏不调用任何delete.
// 4.不要让placement new掩盖了global空间的new
// 5.解决方式是建立一个基类，包含所有正常形式的new，然后在子类里面使用using声明


