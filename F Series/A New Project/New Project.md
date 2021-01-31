STM32环境入门（以stm32f10x系列为例）
对于大部分STM32初学者，遇到的第一个问题就是新建工程。 根据实验，我总结了一套方法： 总体思路：先建立寄存器工程，再扩充库函数

*Step.0.0 安装开发环境

Keil公司旗下的MDK，目前我所安装的版本为MDK5.29，支持AC5（Arm Compiler）版本的编译模式，而5.30之后的均默认开启AC6版本编译模式，新建工程时会产生大量的编译错误和警告，就是因为在AC6的检查中不支持。

*Step.0.1 安装STM32系列单片机支持包

*Step.0.2 获取ARM内核文件、系统文件以及启动文件

内核文件："core_cm3.c" 及其头文件 "core_cm3.h" -- 系统文件："STM32F10X.H" "system_stm32f10x.c" 及其头文件 "system_stm32f10x.h" 启动文件："startup_stm32f10x.s" --

启动文件功能：汇编语言文件，绑定常用函数的入口，引导单片机正确启动，执行程序

*Step.1.0 创建工程文件目录
*Step.1.1 向工程目录挂载文件
*Step.1.2 在MDK内新建工程
*Step.1.3 管理工程项目
在目录 \System 下，添加系统资源管理文件："system_stm32f10x.c" "STM32F10X.H" 在目录 \Core 下，添加内核文件："core_cm3.c" 在目录 \User 下，添加汇编启动文件："startup_stm32f10x.s"

打开 "Options" 选项，切换至 "Target" 选项卡 在 "Code Generation" 栏中的 "ARM Compiler" 菜单，下拉选择 "Use default compiler version 5" 选项，修改至AC5编译模式（5.30之后默认为AC6） 打开 "Options" 选项，切换至 "C/C++" 选项卡 在预处理栏中输入：STM32F10X_HD --根据芯片实际RAM大小有_H（High），_M（Middle），_L（Low） 在文件包含路径中添加相关文件目录：..\Core;..\System --由于工程建立在User文件夹下，因此作为默认目录下的文件不必添加路径
*Step.1.4 验证工程

在目录\User下创建main.c文件，输入以下代码： ** #include "STM32F10X.H"

int main() { ; }

** 在MDK编译器中，函数块的后面必须有新空行，否则会有编译器警告 在新建工程期间出现的相关问题，可参照附录 编译完成后，如没有错误和警告，说明此寄存器版本工程可以使用了

*Step.2.0 添加库函数

*Step.2.1 添加库函数相关头文件

添加 "stm32f10x_it.c" 添加 "STM32F10X_CONF.H" --注意

*Step.2.2 管理工程项目

打开Options选项，切换至C/C++选项卡 在预处理栏中添加：USE_STDPERIPH_DRIVER 在文件包含路径中添加相关文件目录：..\Lib ..\Lib

*Step.2.3 验证工程

这里可以直接编译之前打好的代码，其中的变化已经在头文件和宏定义里面处理过了 编译成功完成后，如没有错误和警告，说明此库函数版本工程可以使用了