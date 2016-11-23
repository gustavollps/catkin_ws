#include "../../include/a_star_test/LibAstar.h"

LibAstar::LibAstar(Point &goal, Point &start):goal_{goal}, start_{start}{}

std::string LibAstar::pathFinder()
{
  static GraphNode *node = new GraphNode(MANHATTAN, goal_,start_,start_,0);

  node->G_ = 0;
  node->F_ = node->H_;

  #ifdef DEBUG2
  ros::Time time = ros::Time::now();
  #endif
  static Point actual_position = start_;
  static GraphNode *temp_node;

  clearLists();  
  clearMap();
  clearDirMap();
  while(!open_list[0].empty()){
    open_list[0].pop();
  }

  open_list[0].push(*node);

  //map[0][2]=1;
  map[3][0]=1;
  map[3][1]=1;
  map[3][1]=1;


//  map[1][2]=1;
//  map[2][2]=1;
//  map[3][2]=1;
//  map[4][2]=1;
//  map[5][2]=1;
//  map[3][2]=1;

//  map[0][6]=1;
//  map[1][6]=1;
//  map[2][6]=1;
//  map[3][6]=1;
//  map[4][6]=1;
//  map[5][6]=1;
//  map[6][6]=1;
//  map[7][6]=1;
//  map[8][6]=1;
//  map[9][6]=1;
//  map[10][6]=1;
//  map[11][6]=1;
  for(int i=0;i<MATRIX_HEIGHT-1;i++){
    map[i][40]=1;
  }
  for(int i=1;i<MATRIX_WIDTH-4;i++){
    map[40][i]=1;
  }
  for(int i=0;i<39;i++){
    map[30][i]=1;
  }
  map[98][99]=1;
  //map[99][98]=1;
  map[98][98]=1;

  #ifdef DEBUG
  printMap();
  #endif

  opened_list[start_.x_][start_.y_] = node->F_;

  while(!open_list[0].empty() && !(node->position_==goal_))
  {
    //std::cout << open_list[0].size() << std::endl;

    #ifdef DEBUG
    std::cout << "New node: " << node[0] << std::endl;
    std::cout << "Goal: " << goal_ << std::endl;
    #endif
    //debug();

    open_list[0].pop();

    if((closed_list[node->position_.x_][node->position_.y_] > node->F_ ||
       closed_list[node->position_.x_][node->position_.y_] == 0) &&
       (opened_list[node->position_.x_][node->position_.y_] >= node->F_))
    {
      closed_list[node->position_.x_][node->position_.y_] = node->F_;
      //opened_list[node->position_.x_][node->position_.y_] = node->F_;
    }
    else if(opened_list[node->position_.x_][node->position_.y_] != 0)
    {
      closed_list[node->position_.x_][node->position_.y_] = opened_list[node->position_.x_][node->position_.y_];
      node->F_ = opened_list[node->position_.x_][node->position_.y_];
      node->G_ = node->F_-node->H_;
    }

    //verifying neighbors
    for(int i = -1; i<2;i++)
    {
      for(int j = -1; j<2;j++)
      {
        Point actual_position(node->position_.x_+i,node->position_.y_+j);
        //std::cout << "Search position: " << node[0].position_ << std::endl;


        //node validation for verification of H and G
        if(validPoint(actual_position))
        {

          //avoid the verification of the same node
          if(!(i==0&&j==0))
          {
            //child node
            GraphNode *temp_node = new GraphNode(MANHATTAN,goal_,actual_position,node->position_,node->G_);

            #ifdef DEBUG
            std::cout << "Neighbors search: " << temp_node[0] << std::endl;
            std::cout << "Father: " << node[0] << std::endl;
            #endif
            //better way to node found, update the length to this node
            if(temp_node->F_ < opened_list[actual_position.x_][actual_position.y_])

            {

              #ifdef DEBUG
              std::cout << "Replacing node" << std::endl;
              std::cout <<  "New node: " << temp_node[0] << std::endl;
              std::cout <<  "Actual position: " << actual_position << std::endl;
              std::cout <<  "Openlist top position: " << open_list[0].top().position_ << std::endl;
              #endif

              if(closed_list[actual_position.x_][actual_position.y_]==0)
              {

                while((open_list[0].top().position_.x_ != actual_position.x_) ||
                      (open_list[0].top().position_.y_ != actual_position.y_))
                {
                  open_list[1].push(open_list[0].top());

                  #ifdef DEBUG
                  std::cout <<  "Popped node: " << open_list[0].top() << std::endl;
                  //getchar();
                  #endif

                  open_list[0].pop();
                }

                #ifdef DEBUG
                std::cout <<  "Last popped node: " << open_list[0].top() << std::endl;
                #endif

                open_list[0].pop();
                open_list[0].push(*temp_node);

                while(!open_list[1].empty()){
                  open_list[0].push(open_list[1].top());
                  open_list[1].pop();
                }
              }
              else{
                closed_list[actual_position.x_][actual_position.y_] = temp_node->F_;
              }

              opened_list[actual_position.x_][actual_position.y_] = temp_node->F_;                            

              delete temp_node;

              dir_map[actual_position.x_][actual_position.y_] = getDir(i,j);


            }
            else if(opened_list[actual_position.x_][actual_position.y_] == 0) //note-yet-verified node
            { //push node

              #ifdef DEBUG
              std::cout << "New node" << std::endl;
              #endif

              //generate node father direcion
              if(dir_map[actual_position.x_][actual_position.y_]=='0')
                dir_map[actual_position.x_][actual_position.y_] = getDir(i,j);

              //add node to openned list
              opened_list[actual_position.x_][actual_position.y_]=temp_node->F_;

              open_list[0].push(*temp_node);

              delete temp_node;

            }

          }

        }

        #ifdef DEBUG
        std::cout << "Top node: ";
        std::cout << open_list[0].top() << std::endl;
        std::cout << "Node priority list:" << std::endl;


        while(!open_list[0].empty()){

          std::cout << open_list[0].top() << std::endl;

          open_list[1].push(open_list[0].top());
          open_list[0].pop();
        }
        while(!open_list[1].empty()){
          open_list[0].push(open_list[1].top());
          open_list[1].pop();
        }

        std::cout << std::endl;
        debug();
        #endif

      }            

    }

    Point temp_point = node->position_;
    delete node;
    GraphNode *node = new GraphNode(MANHATTAN,
                                    goal_,
                                    open_list[0].top().position_,
                                    open_list[0].top().father_,
                                    open_list[0].top().G_);

    #ifdef DEBUG
    std::cout << "Top node: " << open_list[0].top() << std::endl;
    std::cout << "Next node: " << node[0] << std::endl;
    #endif
  }

  delete temp_node;
  delete node;

  #ifdef DEBUG2
  ros::Duration dtime = ros::Time::now()-time;
  std::cout << "Tempo de execução: " << std::endl;
  std::cout << dtime.toSec() << "s" <<std::endl;
  #endif

  #ifdef DEBUG
  debug();
  #endif

  if(open_list[0].empty())
  {
    #ifdef DEBUG2
    std::cout << "Rota não encontrada" << std::endl;    
    getchar();
    #endif
    return "";
  }
  else
  {
    #ifdef DEBUG2
    std::cout << "Rota encontrada" << std::endl;        
    #endif
    std::string route;
    Point position = goal_;

    #ifdef DEBUG
    clearLists();
    #endif

    route = dir_map[position.x_][position.y_];

    #ifdef DEBUG
    printMap();
    clearMap();    
    map[goal_.x_][goal_.y_]=1;
    #endif

    while(!(position == start_))
    {
      switch(dir_map[position.x_][position.y_])
      {
        case 'a':
          position.x_ += 1;
          position.y_ += 1;
          break;
        case 'b':
          position.x_ += 1;
          break;
        case 'c':
          position.x_ += 1;
          position.y_ -= 1;
          break;
        case 'd':
          position.y_ += 1;
          break;
        case 'e':
          position.y_ -= 1;
          break;
        case 'f':
          position.x_ -= 1;
          position.y_ += 1;
          break;
        case 'g':
          position.x_ -= 1;
          break;
        case 'h':
          position.x_ -= 1;
          position.y_ -= 1;
          break;
        default:
          break;
      }

      #ifdef DEBUG
      map[position.x_][position.y_] = 1;
      #endif

      if(position != start_)
      {
        char temp = dir_map[position.x_][position.y_];
        route = temp+route;
      }
      #ifdef DEBUG
      std::cout << "Generating route" << std::endl;
      #endif
    }
    //printMap();

    //std::cout << std::endl;
    //std::cout << std::endl << route << std::endl << std::endl;
    //getchar();
    return route;
  }

}

bool LibAstar::validPoint(Point point){
  return !(point.x_<0||point.x_>MATRIX_HEIGHT-1||point.y_<0||point.y_>MATRIX_WIDTH-1||map[point.x_][point.y_]);
}

void LibAstar::clearLists(){
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      closed_list[i][j]=0;
      opened_list[i][j]=0;
    }
  }
}

void LibAstar::clearMap(){
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      map[i][j]=0;      
    }
  }
}

void LibAstar::clearDirMap(){
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      dir_map[i][j]='0';
    }
  }
}

void LibAstar::printClosedList(){
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      std::cout << closed_list[i][j] << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void LibAstar::printOpenedList(){
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      std::cout << opened_list[i][j] << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void LibAstar::printDirMap(){
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      std::cout << dir_map[i][j] << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void LibAstar::printMap()
{
  for(int i=0;i<MATRIX_HEIGHT;i++){
    for(int j=0;j<MATRIX_WIDTH;j++){
      std::cout << map[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void LibAstar::debug(){
  std::cout << "Opened List" << std::endl;
  printOpenedList();
  std::cout << "Closed List" << std::endl;
  printClosedList();
  std::cout << "Directions map" << std::endl;
  printDirMap();
  std::cout << "List size: " << open_list[0].size() << std::endl;
  std::cout << "Press enter to continue" << std::endl;
  std::getchar();
}

char LibAstar::getDir(int x, int y){
  if(x==-1)
  {
    if(y==-1)
      return 'a';
    if(y==0)
      return 'b';
    if(y==1)
      return 'c';
  }
  if(x==0)
  {
    if(y==-1)
      return 'd';
    if(y==1)
      return 'e';
  }
  if(x==1)
  {
    if(y==-1)
      return 'f';
    if(y==0)
      return 'g';
    if(y==1)
      return 'h';
  }
}
