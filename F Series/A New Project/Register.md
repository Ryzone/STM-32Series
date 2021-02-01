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

然后，利用MDK在MDK-ARM文件夹下新建工程

Project -> New μVision Project... -> 工程名 -> Save

选择对应的芯片

再者，

第四

接着

最后

