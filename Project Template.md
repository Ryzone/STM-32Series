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

  * STD：即Standard Peripheral Libraries，最为ST公司最早推出的标准库
  
  * HAL：硬件抽象层(Hardware Abstraction Layer)，是高级函数封装API，向用户屏蔽了复杂的外设配置过程，具有高移植性
  
  * LL：与STD库类似，Low-Layer属于寄存器级的底层API，有较好的优化，相应可移植性较差，适合快速、轻量级开发

## Step.1 建立工程目录
实际上，工程目录并没有统一的规定，可以说连官方提供的模板都可能因版本而有不同变化。即便如此，我们也能一窥其中的一些共识，通过观察各种路径规划并结合自己的理解，就有了下面的目录模板，在自建工程的时候，就会以此为标准：

<pre>
│  
└─STM32_ProjectTemplate
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

## Step.2 创建寄存器工程

[F Series](https://github.com/Ryzone/STM-32Series/tree/main/F%20Series/A%20New%20Project)|[G Series](https://github.com/Ryzone/STM-32Series/tree/main/G%20Series/A%20New%20Project)
:---:|:---:
[F-Register]()|[G-Register]()
[F-HAL]()|[G-HAL]()
[F-LL]()|[G-LL]()
[F-STD]()|

## Step.3 

##### 附：常见问题与解决方案
