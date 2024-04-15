SET PATH=C:\Keil_v5\ARM\Arm Compiler 6.17\Bin;C:\Program Files\Parallels\Parallels Tools\Applications;C:\Program Files\Python39\Scripts\;C:\Program Files\Python39\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files (x86)\Microsoft SQL Server\120\Tools\Binn\;C:\Windows\SysWOW64\WindowsPowerShell\v1.0\;C:\Program Files (x86)\TortoiseSVN\bin;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Program Files\dotnet\;C:\Program Files\LLVM\bin;C:\Program Files\CMake\bin;C;C:\Program Files (x86)\Git\cmd;C:\Program Files (x86)\QuickTime\QTSystem\;C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin;C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2020-q4-major\bin;C:\Users\gabriel\AppData\Local\Microsoft\WindowsApps;C:\Users\gabriel\AppData\Local\GitHubDesktop\bin;C:\Users\gabriel\.dotnet\tools
SET ARMCC6_ASMOPT=--diag_suppress=9931
SET ARMCC6_CCOPT=--diag_suppress=9931
SET ARMCC6_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=SSE-300-MPS3
SET CPU_VENDOR=ARM
SET UV2_TARGET=Cortex-M55_MPS3
SET CPU_CLOCK=0x017D7840
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\led_port.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\serial.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\platform.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\glcd_v2m-mps3_an547.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\glcd_fonts.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\touch_v2m-mps3.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\main.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\driver_fvp_sse300_mpc.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\driver_i2c.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\driver_spi.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\driver_sse300_ppc.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\driver_usart.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\retarget_io.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\device_definition.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\startup_fvp_sse300_mps3.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\system_sse300mps3.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\img_clothes.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmClang.exe" @".\objects\img_demo_widgets_avatar.__i"
"C:\Keil_v5\ARM\Arm Compiler 6.17\Bin\ArmLink" --Via ".\Objects\lv_template.lnp"
