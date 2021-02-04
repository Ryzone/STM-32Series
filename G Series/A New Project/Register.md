### 寄存器工程(G系列)

#### 首先，我们基于现有目录来添加文件，形成以下结构：

<details>
  <summary> STM32_ProjectTemplate </summary> 
  <pre>
    ├─CMSIS
    │  ├─CoreSupport
    │  │  ├─Inc
    │  │  │      cmsis_armcc.h
    │  │  │      cmsis_armclang.h
    │  │  │      cmsis_armclang_ltm.h
    │  │  │      cmsis_compiler.h
    │  │  │      cmsis_gcc.h
    │  │  │      cmsis_iccarm.h
    │  │  │      cmsis_version.h
    │  │  │      core_cm4.h
    │  │  │      mpu_armv7.h
    │  │  │      
    │  │  └─Src
    │  └─DeviceSupport
    │      ├─Inc
    │      │      stm32g*xx.h
    │      │      system_stm32g*xx.h
    │      │      
    │      └─Src
    │              system_stm32g*xx.c
    │              
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
    │      startup_stm32g*xx.s
    │      STM32_ProjectTemplate.uvprojx
    │      
    └─User
        ├─Include
        └─Source
                main.c
                
  </pre>
</details>

由于CMSIS的演化，新的ARM内核调度都集成在头文件里了

#### 其次，便是利用MDK在MDK-ARM文件夹下新建工程

    Project -> New μVision Project... -> ~工程名称~ -> Save

根据提示选择对应的芯片

    Select Device for Target... -> STMicroelectronics -> STM32G* Series -> ~芯片型号~ -> OK

Manage Run-Time Environment 配置运行环境，一般只要PACK的版本没有问题直接OK就可以

#### 然后，打开<kbd>Manage Project Items</kbd>创建逻辑目录，把需要用到的**源文件**和**汇编文件**都添加进来，方便编译器顺利找到它们

> 这里的目录与上面的文件路径无太大关联，倒是能方便开发者归类和管理文件，不过本身的路径我们已经规划好了，所以如没有特殊情况还是尽量保持一致会比较好

#### 接着，点击<kbd>Options for Target</kbd>按钮，切换内容

**Output** 选项卡：

勾选上*Create HEX File*，使工程输出HEX类型文件

**C/C++** 选项卡：

在*Language/Code Generation*栏中，确保*C99 Mode*框的勾选

> 通过预处理器，编译器可选择具体的初始化方式，正确映射寄存器地址

在*Include Paths*栏中，点击右侧的省略号，添加工程用到的所有头文件路径

> 关于头文件和源文件的管理：在前面创建逻辑目录时，已经将源文件路径告知编译器了，因此这里只需要再添加头文件路径，即可囊括所有工程用到的代码了

#### 最后，在**User/Source**目录下新建**main.c**并输入以下代码：

```
#include "stm32g*x.h"

int main()
{
  return 0;
}

```
注意，代码的最后必须要有多的空行(也许是有编译器读取文件EOF的规定)

编译、汇编、链接一键三连，如果编译器返回了

`0 Error(s), 0 Warning(s).`

说明测试通过，恭喜你，寄存器模板建立成功！

附：[常见问题与解决方案](https://github.com/Ryzone/STM-32Series/blob/main/Project%20Template.md#step5-%E5%B0%8F%E7%BB%93)
