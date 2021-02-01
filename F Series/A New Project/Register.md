# 寄存器工程

首先，我们基于现有目录来添加文件，形成以下结构：

<details>
  <summary> STM32_ProjectTemplate </summary> 
  <pre>
    ├─CMSIS
    │  ├─CoreSupport
    │  │  ├─Inc
    │  │  │      core_cm3.h
    │  │  │      
    │  │  └─Src
    │  │          core_cm3.c
    │  │          
    │  └─DeviceSupport
    │      ├─Inc
    │      │      stm32f10x.h
    │      │      system_stm32f10x.h
    │      │      
    │      └─Src
    │              system_stm32f10x.c
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
    │  │  startup_stm32f10x_hd.s
    │  │  STM32_ProjectTemplate.uvprojx
    │  │  
    │  ├─DebugConfig
    │  ├─Listings
    │  └─Objects
    └─User
        ├─Include
        └─Source
                main.c
  </pre>
</details>

其次便是利用MDK在MDK-ARM文件夹下新建工程，

Project -> New μVision Project... -> 工程名 -> Save

根据提示选择对应的芯片

然后，打开 Manage Project Items，创建逻辑目录并归入工程文件，把需要用到的工程源文件和汇编文件都添加进来，方便编译器顺利找到它们。这里的目录与上面的文件路径无太大关联，倒是能方便开发者归类和管理文件，不过本身的路径我们已经规划好了，所以如没有特殊情况还是尽量保持一致会比较好

接着，点击 Options for Target，切换至


Output 选项卡：



再者，

最后

