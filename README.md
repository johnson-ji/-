# -
C++学习的第一个小软件

简述：基于多态的职工管理系统，系作者第一个程序，作学习存档之用。主要功能包括增删改查、排序以及和文件互通。

要点：
1、职工分为三个类，职工、经理和老板，创建一个基类work作为原型，分别建立三个类用public的方式继承基类，再复写基类中的函数，形成多态，来实现不同类型的职能。再创建一个work *类型指针列表，存放work * workers指针来指向这三个类创建的实例化对象。再创建一个指向指针列表的指针，即work ** emp_arr，用来对列表进行管理。
2、在构造函数中初始化参数时，用程序读取文件中保存的内容，依据①文件不存在，②文件存在但为空，③文件存在且不为空这三种情况对列表长度、列表是否为空和*列表的内容进行初始化，将文件数据写入堆区中。如果发生更改，则将更改后的数据再次写入文件。程序推出后再在析构函数中对堆区中的**emp_arr指向的空间进行释放。
3、在保存数据方面，选择每次在需要新增一个文件时，提前指定增加的人数，开辟一个新的空间。并将旧有的数据转移到一个新空间，再在这个基础上新增数据在新空间。最后释放原本指针指向的旧空间，使work ** emp_arr指针指向新空间。
4、每次实施一个功能时，都要在改变后，更新文件，并且对列表长度、列表是否为空和列表的内容进行更新。

其余要点都较为简单，需要注意的是，本文件存储的方法较为麻烦。应当使用链表之类的方式存储更为简单，但老师采用的这个方法，故没有改变。进一步学习后可再做更改。
