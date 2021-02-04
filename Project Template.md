# 工程模板

---

> STM32系列单片机的学习路上，第一道门槛便是开发环境的搭建与工程模板的建立，首先需要有一个完整的开发环境，才能迈出嵌入式的第一步：

## Step.0 准备开发环境

### 基础部分

+ **MDK-ARM**：Keil Review MDK是Keil公司旗下针对ARM架构微控制器的嵌入式软件开发解决方案，集成了创建、构建和调试嵌入式应用程序所需的所有组件

+ **PACK**：为避免过于臃肿，Keil将MDK附加的软件组件和对微控制器设备的支持以软件包的形式提供，因此在对芯片编程前需要预装相关的芯片包

+ **CMSIS**：CMSIS文件是ARM公司与芯片厂商建立的一套标准，全称CortexMicroController Software Interface Standard，能广泛用于相同Cortex内核的芯片，保证了不同厂商生产的芯片相互兼容：

  - 内核部分(CoreSupport)：由ARM提供的用于访问内核寄存器的名称、地址定义

  - 外设部分(DeviceSupport)：由芯片设计厂商自行引出的片上的核外(片内)外设的地址和中断定义

+ **Startup**：其名称常为"Startup*.s"，是由汇编写成的芯片系统启动文件，用于初始化芯片堆栈空间、中断向量等，最后引导进入main函数执行程序

### 扩展部分

* **STM32CubeMX**：STM32CubeMX是一款图形化工具，它能够通过简单的分步操作，轻易为STM32系列Cortex-M、Linux属Cortex-A内核的MCU与MPU进行配置和初始化，生成对应设备的初始化代码

* **APIs**：
> 封装的函数多了，也便成了库

为适应变化的开发环境，ST公司用标准函数封装起繁琐的寄存器配置，并给出了不同层级的库，省去了学习底层的成本和一步步配置的麻烦，常用的API有以下几种：

  * STD：即Standard Peripheral Libraries，是ST公司最早推出的标准库
  
  * HAL：硬件抽象层(Hardware Abstraction Layer)，是高级函数封装API，向用户屏蔽了复杂的外设配置过程，具有高移植性
  
  * LL：与STD库类似，Low-Layer属于寄存器级的底层API，有较好的优化，相应可移植性较差，适合快速、轻量级开发

## Step.1 建立工程目录
实际上，工程目录并没有统一的规定，可以说连官方提供的模板都可能因版本而有不同变化。即便如此，我们也能一窥其中的一些共识，通过观察各种路径规划并结合自己的理解，就有了下面的目录模板，我在自建工程的时候，会以此为标准：

<details> 
  <summary> STM32_ProjectTemplate </summary>
  <pre>
    │  
    ├─CMSIS
    │  ├─CoreSupport
    │  │  ├─Inc
    │  │  └─Src
    │  └─DeviceSupport
    │      ├─Inc
    │      └─Src
    ├─Drivers
    │  ├─HAL_Driver
    │  │  ├─Inc
    │  │  └─Src
    │  ├─LL_Driver
    │  │  ├─Inc
    │  │  └─Src
    │  └─STD_Driver
    │      ├─Inc
    │      └─Src
    ├─MDK-ARM
    └─User
        ├─Include
        └─Source      
  </pre>
</details>

当然，免不了的还是要强调一下，**文件目录中尽量不要有中文！**

## Step.2 创建寄存器工程

  CMSIS标准的建立，为芯片内核和外设实现一致且简单的软件接口，使寄存器从单纯的总线地址变得有名有姓，奠定了快速开发的基础，绝大部分交互和控制的实现都能通过操作和配置寄存器来实现。而我们常说的基于函数库的开发均在此之上，倘若将工程中各种库的外衣剥去，不变就是寄存器工程了。因此，了解和学习寄存器，对开发来说是很有必要的

>  虽说各系列芯片的工程都是基于CMSIS标准来建立，一种芯片的工程建立方式能很容易应用于其他版本，但随着版本的更新和新型号陆续推出，工程结构仍有异同，因此还是区分讲解为宜

* STM32 F系列：[F Series](https://github.com/Ryzone/STM-32Series/blob/main/F%20Series/A%20New%20Project/Register.md)
* STM32 G系列：[G Series](https://github.com/Ryzone/STM-32Series/blob/main/G%20Series/A%20New%20Project/Register.md)

## Step.3 扩充函数库

|          | [F Series](https://github.com/Ryzone/STM-32Series/tree/main/F%20Series/A%20New%20Project) | [G Series](https://github.com/Ryzone/STM-32Series/tree/main/G%20Series/A%20New%20Project) |
|:---------|:--------:|:--------:|
|    HAL   | [F-HAL]()| [G-HAL]()|
|    LL    | [F-LL]() | [G-LL]() |
|    STD   | [F-STD]()|


## Step.4 机械降神STM32CubeMX

为了解决建立工程模板带来的种种困难，也为了新标准库的加入，加速开发流程，


## Step.5 小结

到这里，工程模板的建立就算是告一段落了，工程模板一旦建立，往后的开发可以直接沿用，快速投身于项目中，不必再反复创建。虽说过程繁琐，但整体并不算难，而在这过程中是能够明白很多工程文件之间的运作关系的。即便如今有了CubeMX这样的新工具，作为开发人员，是需要拥有自行创建工程模板的能力的

- - -

<details> 
  <summary>  附：常见问题与解决方案 </summary>

###### 编译错误：error: L6236E: No section matches selector - no section to be FIRST/LAST.

添加**Startup*.s**文件到项目中

###### 编译警告：

在**Startup*.s**文件中，找到
```
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
                 IMPORT  SystemInit
                 IMPORT  __main

                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP
```
并修改为
```
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
                 ;IMPORT  SystemInit
                 IMPORT  __main

                 ;LDR     R0, =SystemInit
                 ;BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP
```
因为该汇编启动文件规定程序在进入主函数之前，会先进入函数`SystemInit()`初始化系统时钟，有的芯片支撑文件中不一定会自带此函数，导致编译错误，只需将调用部分注释掉即可

###### 编译警告：warning:  #1-D: last line of file ends without a newline



###### 芯片型号不一致

打开 Options for Target ，在**Device**选项卡中可以重新选择芯片型号

###### 默认晶振时间不一致

在**Target**选项卡中，Xtal(Mhz)一栏填写正确的时钟频率

###### 不生成HEX格式文件

首先检查程序编译和生成过程中是否产生错误，若没有，则在**Output**选项卡中勾选*Creat HEX File*

###### 修改工程输出路径

在**Output**选项卡中，点击*Select Folder for Objects*按钮，选择中间文件路径

###### 修改中间文件路径

在**Listing**选项卡中，点击*Select Folder for Listing*按钮，选择中间文件路径

###### 编译不支持内联函数

这是由于工程文件不支持最新的编译版本导致的，可以看到在**C/C++** 选项卡中出现了 *(AC6)* 的字样，Target选项卡中CodeGeneration栏下拉菜单中选择Use Default Compiler version 5

###### C99 Mode

在**C/C++** 选项卡中勾选*C99 Mode*

###### 下载器无法连上

**Debug**选项卡下，确认勾选*Use Debugger*而非*Use Simulator*，下拉选择对应的下载仿真器

点击右侧**Settings**按钮，在内 Debug 选项卡中配置*Port*和*Max Clock*

###### 下载程序不执行

检查程序逻辑无误后，通过板载复位键重置

若需要程序下载后立即执行，则在**Debug**选项卡下点击右侧**Setting**按钮，在内 Flash Download 选项卡中勾选*Reset and Run*

</details>
