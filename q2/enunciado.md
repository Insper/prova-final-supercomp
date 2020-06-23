% SuperComputação
% Igor Montagner

## Questão 2 (3,0)

A flutuação de preços de ações pode ser modelada com séries temporais e sorteios aleatórios. Iremos adotar o seguinte procedimento de simulação, dado um preço inicial $T_0$:

$$
T_i = 1,05 * T_{i-1} - R * \frac{T_{i-1}}{10} 
$$

onde $R = U(0, 1.0)$ retirado de uma distribuição uniforme entre 0 e 1,0.  

### Entrada

```
N T
p01 
p02
...
p0N
```

* `N` é o número de ações a serem simuladas
* `T` é o número de iterações da simulação
* `p0I` é o preço inicial da ação `i`  a ser simulada. 

### Saída

```
p01 p11 p12 ... pT1
....
p0N p1N p2N ... pTN
```

### Implementação

Seu programa deverá implementar a simulação acima para todas as ações passadas na entrada. A implementação deverá ser feita em GPU usando `thrust`. Além de implementar, responda as perguntas abaixo.

1. Precisamos tomar cuidados ao usar geradores de números aleatórios em GPU. Como você gerenciou isso no seu programa?


1. Seu programa deverá permitir usar seeds diferentes para realizar simulações com a mesma entrada e diferentes cenários. Explique como você implementou isso.



