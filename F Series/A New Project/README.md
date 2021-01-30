# 花式新建工程
---
## Step.0 准备开发环境

### 基础部分

+ **MDK-ARM**：Keil Review MDK是Keil公司旗下针对ARM架构微控制器的嵌入式软件开发解决方案，集成了创建、构建和调试嵌入式应用程序所需的所有组件
<\br>
+ **PACK**：为避免过于臃肿，Keil将MDK附加的软件组件和对微控制器设备的支持以软件包的形式提供，因此在对芯片编程前需要预装相关的芯片包
<\br>
+ **CMSIS**：CMSIS芯片文件是ARM与芯片厂商建立的一套标准，全称CortexMicroController Software Interface Standard，能广泛用于相同Cortex内核的芯片，保证了不同厂商生产的芯片相互兼容：
<\br>
  - 内核部分(CoreSupport)：由ARM提供的用于访问内核寄存器的名称、地址定义
  <\br>
  - 外设部分(DeviceSupport)：由芯片设计厂商自行引出的片上的核外(片内)外设的地址和中断定义
<\br>
+ **Startup**：其名称常为"Startup*.s"，是由汇编写成的芯片系统启动文件，用于初始化芯片堆栈空间、中断向量等，最后引导进入main函数执行程序

### 扩展部分

* **API**：
  * STD：
  * HAL：
  * LL：
* **STM32CubeMX**:
