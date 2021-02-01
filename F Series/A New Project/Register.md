# 寄存器工程

首先，在目录下填充文件
<detials>
  <summary> 文件目录 <summary/>
<pre>

└─STM32_ProjectTemplate
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
                
<pre/>
<detials/>
