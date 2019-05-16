class Obstacle
{
  private:
  int x;
  int y;
  int vObs = 2;
  int taille;

  public:
  Obstacle();
  Obstacle(int positionX, int positionY);

  bool colision(int px, int py, int ptaille);

  void avX();
  void avY();

  int getposX();
  int getposY();
  void setposX(int posX);
  void setposY(int posY);
  int getTaille();

};
