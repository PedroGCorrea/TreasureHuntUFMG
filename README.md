Aluno: Pedro Guimarães de Deus Corrêa <br><br>
Professores:<br>
Pedro Olmo<br>
Cristiano Arbex<br> 
Guilherme de Castro

Descrição da Prática (Resumo):

Nesta prática você vai implementar um jogo que mistura ideias do jogo batalha naval com jogo da memória. Imagine um cenário em que uma região TAM_Y x TAM_X (p.ex.: 400m x 800m) é dividida em um grid LINHAS x COLUNAS (p.ex.: 8 linhas x 20 colunas). Vamos chamar cada célula deste grid de Tile. Um Tile é uma região retangular no espaço original que pode conter prêmios de diferentes valores. Para verificar se um Tile tem um prêmio e obter o prêmio, o jogador precisa investigar ("cavar") essa região. Uma vez que o Tile é investigado pela primeira vez, o prêmio é obtido pelo jogador e não fica mais disponível para investigações futuras.

Assim, você vai implementar um jogo de dois jogadores em que eles alternadamente indicam uma região no espaço original para ser investigada. Por exemplo, se o espaço original for de 400m x 800m, a primeira jogada do jogador 1 pode ser 244 789, que é uma coordenada no espaço original para ele investigar. Essa coordenada está associada a um Tile no grid LINHAS x COLUNAS, que é investigada a fim de verificar se nela há um prêmio. Se o grid tiver 8 linhas e 20 colunas, então essa coordenada está associada ao Tile da linha 4 (a quinta linha) e da coluna 19 (a vigésima coluna). Se nesse Tile há um prêmio, some o valor deste prêmio à pontuação do jogador. Marque também que esse Tile já foi investigado para que futuras investigações não somem o prêmio contido nela ao jogador.

O jogo é realizado de forma alternada entre os jogadores e termina de duas maneiras:<br>
  1- Quando todos os Tiles estiverem sido investigados;<br>
  2- Quando um jogador, por três vezes, investigar um Tile que foi previamente investigado.

A ação de cada jogador é indicar (via scanf) coordenadas do espaço original. Se for uma coordenada dada como entrada for associada a um Tile que ainda não foi investigado, some o prêmio do Tile à pontuação do jogador e marque que o tile foi investigado. Se for uma coordenada dada como entrada for associada a um tile que já foi investigado, tire uma vida do jogador. Se a coordenada não for associada a nenhum Tile (p.ex.: -1, 10000), tire uma vida do jogador.

Mudança do Aluno:
Se o usuario colocar, especificamente, x = -1 e y = -2, o jogo se encerra. (Utilizado para depurar sem precisar matar o terminal)

Futuros UPDATES: Integrar biblioteca gráfica (Allegro);
