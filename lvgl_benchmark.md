# LVGL Benchmark

## 1 Overview

This is a benchmark report for comparing performance differences between LVGL baseline and LVGL plus arm-2d acceleration (taking advantage of Helium technology). 

**NOTE:** Due to LVGL's own rendering schema, the result **cannot** be interpreted as Helium acceleration vs C implementation, it is not a fair comparison. For example, in the scene **Image chorma keyed**, the report shows almost **10x** performance (**987%**), this is because in the baseline LVGL repeats its decoding-transform iterations for many times untill all lines are processed, and in arm-2d acceleration, the process is only performed once. 

**The result truly shows the advantage of using arm-2d to accelerate LVGL when Helium technology is available** but doesn't not reveal the right performance ratio between a C verison and a Helium accelerated version for a given 2D image processing algorithm. 

### 1.1 Test Environment

#### 1.1.1 Hardware

- MPS3
- Processor: **Cortex-M55 (r1p0)**
- System Frequency: **60MHz**
- LCD: 320*240 RGB565 8080 interface 

#### 1.1.2 Software

- IDE: [**MDK** **5.37** (Community Edition)](https://www.keil.com/pr/article/1299.htm)
- Compiler: **Arm Compiler 6.18 (built-in compiler in MDK)** with standard c library
- [LVGL: **v8.3.0-dev (cmsis-pack v1.0.4)**](https://github.com/lvgl/lvgl/raw/ce0605182c31e43abc8137ba21f237ec442735bc/env_support/cmsis-pack/LVGL.lvgl.1.0.4.pack)
- [Arm-2D: **v1.0.0-preview-beta1**](https://github.com/ARM-software/EndpointAI/raw/772f45de0037927b504095009b94cac49275bd28/Kernels/Research/Arm-2D/cmsis-pack/Arm.Arm-2D.1.0.0-preview-beta1.pack)

#### 1.1.3 Configuration

- LVGL (configured in `lv_conf_cmsis.h`)

  - set `LV_COLOR_DEPTH` to `16`
  - set `LV_MEM_SIZE` to `(64U * 1024U)`
  - set `LV_DISP_DEF_REFR_PERIOD` to `2`
  - RTE Configuration

  ![RTE](./documents/pictures/RTE) 

  

  - Source code

  ```c
  static void on_benchmark_finished(void)
  {
      disp_enable();
  }
  
  int main(void)
  {
      
      lv_init();
      lv_port_disp_init();
      lv_port_indev_init();
  
      __LL_LCD_PRINT(24, 0, "Running LVGL Benchmark...");
      __LL_LCD_PRINT(25, 0, "Please stand by...");
      __LL_LCD_PRINT(28, 0, "NOTE: You will NOT see anything until the end.");
  
      disp_disable();
      
      lv_demo_benchmark_set_finished_cb(&on_benchmark_finished);
      lv_demo_benchmark();
      
      while(1) {
          lv_timer_handler();
      }
  }
  ```

  

- Arm-2D (configured in `arm_2d_cfg.h`)
  - set `__ARM_2D_HAS_ASYNC__`to `0`
  - set `__ARM_2D_HAS_ANTI_ALIAS_TRANSFORM__` to `1`
  - set `__ARM_2D_CFG_SUPPORT_COLOUR_CHANNEL_ACCESS__` to `1`



## 2 Result



**Table 2-1 LVGL Benchmark (baseline vs arm-2d acceleration)**

| No.  | Scene                                | LVGL-baseline | LVGL+Arm-2D | Ratio  |
| ---- | ------------------------------------ | ------------- | ----------- | ------ |
|      | Weighted FPS                         | 279           | 430         | 154.1% |
|      | Opa. speed                           | 94%           | 65%         | 69.1%  |
| 0    | Rectangle                            | 204           | 231         | 113.2% |
| 1    | Rectangle + opa                      | 100           | 141         | 141.0% |
| 2    | Rectangle rounded                    | 131           | 139         | 106.1% |
| 3    | Rectangle rounded + opa              | 74            | 110         | 148.6% |
| 4    | Circle                               | 69            | 74          | 107.2% |
| 5    | Circle + opa                         | 44            | 73          | 165.9% |
| 6    | Border                               | 181           | 207         | 114.4% |
| 7    | Border + opa                         | 163           | 188         | 115.3% |
| 8    | Border rounded                       | 121           | 133         | 109.9% |
| 9    | Border rounded + opa                 | 109           | 127         | 116.5% |
| 10   | Circle border                        | 59            | 61          | 103.4% |
| 11   | Circle border + opa                  | 50            | 58          | 116.0% |
| 12   | Border top                           | 142           | 145         | 102.1% |
| 13   | Border top + opa                     | 135           | 143         | 105.9% |
| 14   | Border left                          | 142           | 159         | 112.0% |
| 15   | Border left + opa                    | 138           | 152         | 110.1% |
| 16   | Border top + left                    | 124           | 131         | 105.6% |
| 17   | Border top + left + opa              | 116           | 125         | 107.8% |
| 18   | Border left + right                  | 113           | 121         | 107.1% |
| 19   | Border left + right + opa            | 105           | 114         | 108.6% |
| 20   | Border top + bottom                  | 120           | 121         | 100.8% |
| 21   | Border top + bottom + opa            | 114           | 121         | 106.1% |
| 22   | Shadow small                         | 38            | 44          | 115.8% |
| 23   | Shadow small + opa                   | 35            | 43          | 122.9% |
| 24   | Shadow small offset                  | 40            | 47          | 117.5% |
| 25   | Shadow small offset + opa            | 33            | 43          | 130.3% |
| 26   | Shadow large                         | 19            | 24          | 126.3% |
| 27   | Shadow large + opa                   | 16            | 24          | 150.0% |
| 28   | Shadow large offset                  | 20            | 25          | 125.0% |
| 29   | Shadow large offset + opa            | 17            | 25          | 147.1% |
| 30   | Image RGB                            | 814           | 3918        | 481.3% |
| 31   | Image RGB + opa                      | 424           | 1079        | 254.5% |
| 32   | Image ARGB                           | 393           | 415         | 105.6% |
| 33   | Image ARGB + opa                     | 310           | 405         | 130.6% |
| 34   | Image chorma keyed                   | 428           | 4225        | 987.1% |
| 35   | Image chorma keyed + opa             | 312           | 1023        | 327.9% |
| 36   | Image indexed                        | 231           | 235         | 101.7% |
| 37   | Image indexed + opa                  | 199           | 228         | 114.6% |
| 38   | Image alpha only                     | 218           | 216         | 99.1%  |
| 39   | Image alpha only + opa               | 189           | 213         | 112.7% |
| 40   | Image RGB recolor                    | 311           | 864         | 277.8% |
| 41   | Image RGB recolor + opa              | 247           | 563         | 227.9% |
| 42   | Image ARGB recolor                   | 251           | 369         | 147.0% |
| 43   | Image ARGB recolor + opa             | 221           | 357         | 161.5% |
| 44   | Image chorma keyed recolor           | 262           | 856         | 326.7% |
| 45   | Image chorma keyed recolor + opa     | 218           | 532         | 244.0% |
| 46   | Image indexed recolor                | 182           | 220         | 120.9% |
| 47   | Image indexed recolor + opa          | 165           | 214         | 129.7% |
| 48   | Image RGB rotate                     | 101           | 99          | 98.0%  |
| 49   | Image RGB rotate + opa               | 75            | 98          | 130.7% |
| 50   | Image RGB rotate anti aliased        | 43            | 106         | 246.5% |
| 51   | Image RGB rotate anti aliased + opa  | 37            | 100         | 270.3% |
| 52   | Image ARGB rotate                    | 88            | 91          | 103.4% |
| 53   | Image ARGB rotate + opa              | 77            | 90          | 116.9% |
| 54   | Image ARGB rotate anti aliased       | 37            | 37          | 100.0% |
| 55   | Image ARGB rotate anti aliased + opa | 35            | 37          | 105.7% |
| 56   | Image RGB zoom                       | 175           | 175         | 100.0% |
| 57   | Image RGB zoom + opa                 | 134           | 176         | 131.3% |
| 58   | Image RGB zoom anti aliased          | 75            | 172         | 229.3% |
| 59   | Image RGB zoom anti aliased + opa    | 66            | 163         | 247.0% |
| 60   | Image ARGB zoom                      | 154           | 162         | 105.2% |
| 61   | Image ARGB zoom + opa                | 137           | 163         | 119.0% |
| 62   | Image ARGB zoom anti aliased         | 65            | 66          | 101.5% |
| 63   | Image ARGB zoom anti aliased + opa   | 62            | 65          | 104.8% |
| 64   | Text small                           | 15            | 16          | 106.7% |
| 65   | Text small + opa                     | 15            | 17          | 113.3% |
| 66   | Text medium                          | 15            | 16          | 106.7% |
| 67   | Text medium + opa                    | 14            | 16          | 114.3% |
| 68   | Text large                           | 15            | 16          | 106.7% |
| 69   | Text large + opa                     | 14            | 16          | 114.3% |
| 70   | Text small compressed                | 0             | 0           | 0.0%   |
| 71   | Text small compressed + opa          | 19            | 19          | 100.0% |
| 72   | Text medium compressed               | 19            | 18          | 94.7%  |
| 73   | Text medium compressed + opa         | 19            | 19          | 100.0% |
| 74   | Text large compressed                | 22            | 23          | 104.5% |
| 75   | Text large compressed + opa          | 22            | 23          | 104.5% |
| 76   | Line                                 | 59            | 64          | 108.5% |
| 77   | Line + opa                           | 57            | 66          | 115.8% |
| 78   | Arc think                            | 88            | 90          | 102.3% |
| 79   | Arc think + opa                      | 86            | 88          | 102.3% |
| 80   | Arc thick                            | 90            | 92          | 102.2% |
| 81   | Arc thick + opa                      | 85            | 92          | 108.2% |
| 82   | Substr. rectangle                    | 242           | 251         | 103.7% |
| 83   | Substr. rectangle + opa              | 291           | 317         | 108.9% |
| 84   | Substr. border                       | 291           | 319         | 109.6% |
| 85   | Substr. border + opa                 | 286           | 311         | 108.7% |
| 86   | Substr. shadow                       | 328           | 345         | 105.2% |
| 87   | Substr. shadow + opa                 | 322           | 349         | 108.4% |
| 88   | Substr. image                        | 5380          | 5282        | 98.2%  |
| 89   | Substr. image + opa                  | 5962          | 5247        | 88.0%  |
| 90   | Substr. line                         | 333           | 341         | 102.4% |
| 91   | Substr. line + opa                   | 344           | 381         | 110.8% |
| 92   | Substr. arc                          | 81            | 81          | 100.0% |
| 93   | Substr. arc + opa                    | 80            | 80          | 100.0% |
| 94   | Substr. text                         | 57            | 57          | 100.0% |
| 95   | Substr. text + opa                   | 57            | 58          | 101.8% |



**Figure 2-1 Performance Ratio (Arm-2D acceleration over baseline)**

![Figure2-1](./documents/pictures/figure2-1) 