-O1 -O2 -O3 — разные уровни оптимизации

-Os — оптимизация размера (.text раздел в objdump 235)

-Ofast — оптимизация скорости (.text раздел в objdump 1438)

-Og — оптимизация для дебага


g++ complex.cpp

time: 0.665s 0.081s 0.240s size: 17408

g++ -O0 complex.cpp

time: 0.307s 0.102s 0.044s size: 17408

g++ -O1 complex.cpp

time: 0.271s 0.067s 0.076s size: 17272

g++ -O2 complex.cpp

time: 0.282s 0.108s 0.034s size: 17272

g++ -O3 complex.cpp

time: 0.280s 0.087s 0.056s size: 17272

g++ -Os complex.cpp

time: 0.349s 0.133s 0.037s size: 17248

g++ -Ofast complex.cpp

time: 0.347s 0.146s 0.036s size: 18848

g++ -Og complex.cpp

time: 0.344s 0.125s 0.037s size: 17344a