Artifical Idiot 
Author: Devendra Singh 

─── 1. Structure ──────────────────────────────── 

src/
    ├── main.cpp
    ├── kgram.h
    ├── kgram.cpp
    ├── generator.h
    ├── generator.cpp
    ├── Makefile
    ├── file1.txt
    ├── file2.txt
    └─── README.md

─── 2. Flow ─────────────────────────────────────

L0:                          Main.cpp
                                 ↓
L1.1:              Kgramz object <- kgram.cpp
                                 ↓
L1.2:   checkfile() → readline() → build freq & nextmap <- kgram.cpp
                                 ↓
L2.1:     Generator object (gets freq & nextmap) <- generator.cpp
                                 ↓
L2.2:                generate() <- generator.cpp
                                 ↓
                        OUTPUT GENERATED TEXT

─── 3. Output ────────────────────────────────────

─── AFTER LEVEL 1 ──────────────────

K-gram frequencies:
 lab y : 0.047619
 this  : 0.047619
 will  : 0.047619
 write : 0.047619
 you w : 0.047619
In thi : 0.047619
ab you : 0.047619 ...

Next-character probabilities:
 lab y ->  (o, 1)
 this  ->  (l, 1)
 will  ->  (w, 1)
 you w ->  (i, 1)
In thi ->  (s, 1)
ab you ->  ( , 1)
b you  ->  (w, 1)
you wi ->  (l, 1) ...

─── AFTER LEVEL 2 ──────────────────
./slm 6 file4.txt 10
this lab y

#Observation: With higher length of k-gram, words do start making sense.
