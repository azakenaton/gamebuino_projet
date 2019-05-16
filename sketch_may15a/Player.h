class Player 
{
  private:
  
  int x;
  int y;
  int player_vit = 2;
  int taille;

  public:

  Player();
  Player(int posX, int posY);

  int getposX();
  int getposY();
  void moove_player();
  int getTaille();
};
