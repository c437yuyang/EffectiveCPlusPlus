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
// 尽量用const 变量替换宏定义，宏定义可能使目标码变大，并且编译报错的信息也不好找
// 2.class专属常量，static const int NumTurns=5; 
// static确保只有一份，写作成员确保作用域，可加private等控制符
// 但之后必须在实现文件里面进行定义（因为是静态变量）：
// const int ClassName::NumTurns;(现在的新编译器通常都可以in-class初值设定，const static成员和普通成员可以，non-const static成员不行)
// 参见01_01
// 3.尽量以const常量替换#define，
// 如：#define ASPECT_RATIO 1.653=>const double Aspect_Ratio=1.653
// 类内无法in-class初值设定的时候，用enum实现
//
// 4.3.用inline-template可以实现对宏的替换
// 参见01_02
// 5.#include #ifdef 仍然无法被替代

//条款03:多使用const
// 1.const在*左边，被指是常量，const在*右边，指针是常量，两边，都是常量
// 所以const int* a;和int const * a;都是指向常量
// 
// 2.mutable修饰的成员，即使在const成员函数内也可以被修改
// 3.返回const，可以防止一些无意义的客户端错误(自定义数据类型可能被一些无意义的赋值操作，==写成了=)
// 4.const成员函数的作用:(1):使接口容易理解，哪些接口会修改对象哪些不会(2):使得操作const对象成为可能，因为很多地方都是pass-by-reference-to-const
// 5.两个成员函数如果只是常量性不同，可以被修改，const对象会自动调用const版本的函数
// 6.const成员函数里面可以修改static成员以及mutable成员，参见03_01
// 7.如果const和non-const版本代码重复，应该使non-const调用const版本实现。但反向做法是错误的。
// 8.bitwise-constness 是任何一个比特都不能被改变，logical-constness意在可以改变其中一些，用mutable修饰

//条款04:确保对象在使用前被初始化
// 1.使用成员初值列（member initialization list）进行初始化，这种方式会调用相应的构造函数版本
// 初始化发生在进入构造函数体之前，如果存在多个构造函数，都有自己的初值列，会带来重复的情况下，
// 可以选择将赋值和初始化代价一样的部分封装进一个Private函数来调用，避免重复
// 即使内置内型初始化和拷贝赋值的代价一致，建议也统一成都用初始化
// 初值列里面可以直接()，不带值，代表调用默认初始化
// const和reference必须使用初值列初始化，不能被赋值
// 初值列里初始化的顺序取决于成员在class中的声明顺序，和排列无关
// 2. static对象的析构函数会在main结束时自动调用
// 3.不同编译单元(源文件)的初始化顺序是不明确的，
// 所以使用local-static对象替换non-local-static对象(global)，类似于单例模式
// 函数内的local static对象会在函数被调用期间首次遇上该对象之定义式时被初始化。
//
// 
//条款05:C++编译器默认生成的函数 
// 1.声明一个空类(class A{};),编译器自动生成:(1):默认构造函数(2)拷贝构造(3)默认析构(4)拷贝赋值
// 这些函数只有被调用，才会被编译器创建出来，这些函数都是public且inline的
// 默认构造函数只有自己未显示定义构造函数才会生成
// 2.当成员内部有ref和const的时候，
// 如果不手动声明拷贝赋值，编译器不会自动生成拷贝赋值，因为这两种情况不允许更改
// 3.如果base class将copy assignment声明为private,那么其derived class无法自动生成

//条款06：若不想使用编译器自动生成的函数，应该明确拒绝
// 1.将你不希望使用的函数声明为private并且没有实现
// 2.可以写成继承自一个UnCopyable类，方便
// 
// 
//条款07：为多态基类声明virtual析构函数
// 1.polymorphic(带有多态性质的)base class都应该声明一个virtual析构函数，
// 否则在出现多态性的时候(通过父类指针调用delete)，将会只删除基类部分,出现部分析构
// 2.如果class带任何virtual函数，就应该声明一个virtual析构函数
// 3.如果class不作为base class使用，就不应该有virtual析构函数，virtual函数会使得对象体积变大，并且不再具有移植性。
// 4.声明一个纯虚(virtual void xxx()=0)，可以让这个类无法实例化(abstract)
// 5.纯虚析构函数必须有定义体(常常为空)，参见07

//条款08:别在析构函数里抛异常
// 1.如果被析构函数调用的函数可能抛出异常，则应该在析构函数里捕捉并吞掉，而不是继续让其传播
// 

//条款09:不要在构造函数和析构函数里面调用virtual函数
//1.因为派生的的构造函数执行过程是，先构造父类部分，在构造派生类本身，
// 如果在派生类构造函数里面调用的话，直接就是调用父类的函数了
// 非正式的说法:在base class构造期间，virtual函数不是virtual函数
// 2.析构函数一开始执行，子类部分先被析构，就成了一个基类对象了，此时也会去调用父类的函数
// 3.如果需要在构造函数里面调用某个函数，最好是调用static成员，会先于普通成员初始化

//条款10:令operator=返回 reference to *this

//条款11:在operator=中处理自我赋值
// 1.如a[i]=a[j],*px=*py，都可能出现自赋值的现象
// 处理例如：if(this==&rhs) return *this;
// 但通常涉及内存分配的还需要考虑异常安全，这时候做法是先备份之前的内容，分配完成之后再delete
// 以及swap-copy技术
// 
//
//条款12:复制对象不要忘记其中任何一个成分
// 1.子类的copying函数里面，不要忘记父类的成员的复制(但这些成员通常是private)，
// 所以正确的做法是子类去调用父类的copying函数来实现复制
// 2.不要让copy constructor去调用copy assignment，反过来也是一样的，
// 正确的做法是实现一个private的Init函数供两个copying函数调用
// 
//
//条款13:以对象管理资源
// 1.auto_ptr可以利用元素的析构函数进行自动的内存管理，但是不适用于动态数组的管理
// 2.auto_ptr和shared_ptr都是delete,而不是delete []
// 3.为什么没有针对动态数组的auto_ptr? 因为vector和string总是可以替代动态数组
// 4.工厂类的函数返回指针非常容易引起资源泄露，因为用户很容易忘记delete,因此需要更改，参见条款18


//条款16:new 和delete形式要一致
// 1.尽量不要对数组进行typedef,比如 typedef string AddrLines[100]; 但是delete的时候，不知道是数组，就只用了delete
// 因为其实vector和string足以替代所有的数组操作
//
//
//条款17:用独立语句将newed对象置入智能指针
// 1.对于processWidget(std::shared_ptr(new Widget()),priority()) 这个调用而言
// std::shared_ptr(new Widget())和priority()的调用不一定谁先谁后，所以如果先new Widget(),
// 然后priority(),但是报了异常的话，shared_ptr就没有管理到对象，就内存泄露了
// 2.解决办法就是，把std::shared_ptr(new Widget())单独拿出来作为一行语句。

//条款18:让接口容易被正确使用，不易被误用
// 1.许多客户端错误可以用导入新类型的方式避免,参见18_01
// 2.返回指针的工厂函数，用户可能有两个错误:(1)忘记delete(2)delete多次
// 3.所以干脆就让工厂函数返回shared_ptr
// 4.shared_ptr可以指定deleter完成自己指定的删除操作

//条款19:设计class犹如设计type
// 1.本条款讲了设计一个新class的所有注意事项(需要考虑的问题)

//条款20:尽量以pass-by-reference-to-const 替换 pass-by-value
// 1.可以避免构造函数和析构函数的无谓调用
// 2.有const的情况下可以防止对象被改变
// 3.by-reference可防止slicing(对象切割)问题，
// pass by value如果是子类对象传入基类形参的话，会被直接切割成子类对象
// C++编译器底层，reference通常以指针实现出来
// 4.pass-by-value适用于:内置类型，stl迭代器,函数对象


//条款21:必须返回对象时，千万不要返回reference
// (看到一个引用，就要认为他是一个别名，那么他本来的名字是什么?)
// 1.不要返回local对象的reference或者指针，会出大错
// 在stack上创建的对象压根出了代码块就不存在了
// 在heap上创建的对象如果被你返回了引用，根本没有办法delete
// (有时候因为一些中间情况，根本没法获得其指针来delete)
// 2.也不要用static对象的方法来避免多次调用构造函数和析构函数，这里就要选择承受这点代价
// 

//条款22:尽量把成员声明为private
// 1.声明为public或protected都是没有封装性
// 封装性主要跟当其内容改变时可能造成的代码破坏量成反比
// 改变,比如从代码中移除它(如果不封装，需要改变的地方就到处都是，封装了，需要改变的就只有一个接口函数)
// 2.可以让用户在使用的时候，.的时候不用考虑带不带括号(如果全部进行封装了，就全部都带括号)
// 

//条款23:尽量以non-member non-friend 函数替换member函数
// 1.推崇封装的原因:能够使被改变的事物只影响有限的客户
// 2.non-member non-friend不会增加 能够访问class之内private成员的函数数量
// 3.建议做成一个Unity类，提供静态函数去调用这些member函数，定义于同一个namespace里面
// 4.同一个namespace，包含不同的头文件，针对不同的功能
// 
//条款24:如果需要为某个函数的所有参数进行类型转换，那么这个函数必须是non-member
// 1.能够执行隐式类型转换的条件:参数被置于参数列表内时
// 例子: oneHalf.operator*(2) //此时2在列表内，发生隐式转换(假设构造函数不是explicit)
// 所以最终把这种函数声明为non-member是最好的选择，
// const Rational operator*(const Rational& rhs,const Rational& lhs)//这样两个参数就都可以放在列表里面了
// 
// 
//条款25:swap函数的高效率版本
// 1.当swap缺省版本效率不高的时候（内部含有指针或者大量数据），提供一个public成员函数
// 让其高效的交换你的类型的两个对象
// 2.在你的class或template所在命名空间提供一个non-member的swap调用你写的成员函数
// 3.为你的class特性化std::swap
// 4.确保调用swap的时候包含一个using std::swap，保证调用最优版本的swap


//条款26:尽可能延后变量定义式出现的时间
// 1.当出现前面报错，直接return或者中断的操作，应该尽量延后定义，来避免构造函数调用的代价
// 2.尽量在确定知道要用一个变量的时候才定义，避免出现先调用默认构造函数，再赋值，
// 而是直接调用有参构造函数赋有意义的初值
// 3.循环的情况下，除非你知道赋值成本比"构造+析构"低，那么应该将定义写在循环内部 
// 

//条款27:尽量少做转型操作


//条款28:避免返回handles指向对象内部成分
// 1.避免返回指向对象内部的reference,pointer,iterator等等
// 2.成员函数如果返回成员的引用，最好是const的，这样才不会使访问控制修饰符失效
// 

//条款30:inline函数
// 1.inline适用于小型，被调用频繁的函数身上
// 2.过度热衷inline会使程序体积庞大(inline就是在编译的时候，用函数体代替函数名(C#的CLI例外，是在运行时))
// 3.编译器会拒绝太过于复杂的(带循环或者递归的)函数，以及所有的virtual函数
// 因为virtual是动态绑定，编译器在编译的时候根本不知道调用哪个函数
// 4.函数指针的inline不一定起作用
// 5.inline函数缺点是，一旦函数被改变，所有用到此函数的程序都必须重新编译
// 如果不是inline的话，直接重新连接即好
// 

//31.将文件间的编译依存关系降到最低(其实就是.NET在学的降低不同层之间的耦合，通过接口)
// 1.尽量用声明替换定义，就能够完成调用了已经
// 2.#include <iosfwd>，这种xxxfwd的头文件里面只包含声明式
// 3.使用Interface classes来制作handle class，调用的时候用智能指针便可实现内存自动管理
// 4.要使Interface classes能够实例化，可以采用在这个接口内定义一个static的工厂性质的create方法返回这个接口的指针
// ，后面再根据实现这个接口的derived class动态返回所需要对象

//32.public继承一定要是is-a的关系
// 1.public主张继承，能够实施于base class对象身上的每件事情都能实施于derived class身上
// 2.class之间的关系:is-a has-a is-implemented-in-terms-of
// 

//33.避免隐藏继承而来的名称
// 1.详情参见Test_Cpps_26_01
// 2.如果正在使用public继承却有不继承那些重载函数，就是违背了is-a的关系
// 3.using或者转交函数可以实现访问被屏蔽的父类函数

//34.non-virtual pure-virtual impure virtual
// 1.pure virtual是希望子类必须重新实现自己的版本（接口继承）
// 2.impure virtual是希望子类接口继承并且有缺省版本
// 3.non-virtual是希望子类不要去改写，就直接用父类的版本
// 4.pure virtual父类也可以写实现代码，调用的时候Derived->Base::func()

//36.不要重新定义继承来的non-virtual函数

//37.绝不重新定义继承而来的缺省参数值(只考虑带有缺省参数的virtual函数这种情况)
// 1.virtual函数是动态绑定，而缺省参数则是静态绑定的
// 所以:Base *p = new Derived(); 这种情况下，调用
// p->VirtualFunction() , 函数是调用了子类的，但是缺省参数还是用的父类的
// 2.就算是子类和父类的缺省参数想同也不要再重新写一次，第一是代码重复，第二是一旦父类改变，所有子类都要变，耦合性太强


//38.Model has-a or is-implemented-in-terms-of through composition
// 1.public 继承代表is-a，而复合意味着has-a或者is-implemented-in-terms-of
// 2.has-a在应用域出现，is-implemented-in-terms-of发生于实现域
// 3.详情可看用STL的list来实现Set的做法


//派生类与基类的类型转换(来自c++primer15.2.3)
// 1.自动类型转换只对指针或者引用类型有效(多态的时候)
// 2.其他情况下，将一个派生类对象赋值给一个基类对象或者用来初始化基类对象，都是调用的基类里面定义的
// copying函数，故只处理了基类部分的成员。但是这里最后的效果看上去就像是执行了类型转换

//派生访问说明符的作用(来自c++primer15.5)
// 1.派生访问说明符的目的是控制派生类用户(包括派生类的派生类)对于基类成员的访问权限
// 并不影响派生类的成员(本身)或友元对于基类的访问，这个访问只取决于基类成员的访问说明符
// 2.派生访问说明符还控制继承自派生类的新类的访问权限，比如如果一个成员int m1基类里面是public,但是是private继承，
// 则在此派生类里面,m1是private的(但是仍然不影响派生类去访问这个成员，在类内),那么理所应当的，派生类的用户和派生类的派生类
// 就无法访问m1了

//39.private继承的使用
// 1.private继承的时候，子类对象是无法转型成父类的，不是is-a的关系了
// 2.private继承而来的父类的对象在子类中都是private的，无论之前是public or protected
// 3.private继承只意味着希望使用父类中的实现，接口部分被抛弃(全是private)
// 4.private继承还可以用在EBO(empty base optimization，空白基类最优化)中
// 因为一个空类型总是占一个字节(编译器默认分配一个char通常)，但是当这个空白类被用于组合的时候，
// 由于前面可能有int或者其他类型的数据，最终内存对齐就不止占一个字节了，造成浪费，这时可以采用
// private继承，就可以保证只占一个字节,并且也还是能够实现所需要的组合功能





