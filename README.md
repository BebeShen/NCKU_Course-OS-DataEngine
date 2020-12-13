# Operating System HW3 DataEngine

## 說明
https://hackmd.io/@dsclab/rJDIP8YYv

## 作業目標
* 請撰寫一支 Key-Value Stroages 的程式，其功能是能夠處理 PUT、GET、SCAN 指令，且處理的資料量必須大於電腦記憶體的容量。
* 請觀察及分析程式執行期間，包括但不限於CPU、Memory、Disk I/O的使用情況，探討作業系統是如何服務我們的程式。
* 請說明你所設計的整理資料作法，並分析這些設計在我們存取資料的時候，如何能提供較佳的存取效率
## 環境說明
* **OS**: Windows 10 Home 19042.685
* **CPU**: Intel(R) Core(TM) i5-7300HQ CPU @ 2.50GHz   2.50 GHz
* **Ｍemory**: 8GB
* **Programming Language(version)**: C/C++(g++ 8.1.0)
## 編譯
```bash=
# 編譯(O3優化程式執行)
g++ .\DataEngine.cpp -O3 -o F74072235.exe 
# 或是
g++ .\DataEngine.cpp -o F74072235.exe

# 執行
./F74072235.exe [input data path]
# 例如：
#     ./F74072235 ./1.input
#         會產生 1.output
#     ./F74072235 /home/Projects/HW3_P76081043/2.input
#         會產生 2.output
# 若inputdata全為"PUT"則不產生.output檔案
```
## 程式說明
