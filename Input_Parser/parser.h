class input_parser{
protected:
    FILE *fin;///Input file
    static const int max_load=1<<10;///Maximum Allocation
    size_t pos;///Index of the buffer
    char buffer[max_load];///Input is being store here
public:
    input_parser():pos(0){}
    input_parser(const char *);///Opens the specified file
    void open(const char *);///^
    template<class T>
    void read(T &);///Read function
    void read(){}
    template<class T,typename ... Args>
    void read(T & ,Args&...args);
    void read(char *,size_t);///Read a string
    inline char next();///Advances the buffer
};

input_parser::input_parser(const char * fName){
    this->fin=fopen(fName,"r");
    this->pos=0;
}

void input_parser::open(const char *fName){
    delete this->fin;
    memset(this->buffer,0,sizeof(this->buffer));
    this->fin=fopen(fName,"r");
    this->pos=0;
}

inline char input_parser::next(){
    if(this->pos==max_load)
            fread(this->buffer,1,max_load,this->fin),this->pos=0;
    return this->buffer[this->pos++];
}

template<class T>
void input_parser::read(T & nr){
    char c;
    int semn=1;
    nr=0;
    c=this->next();
    while(!isdigit(c) && c!='-')
        c=this->next();
    while(c=='-')
        c=this->next(),semn*=-1;
    while(isdigit(c))
        nr=nr*10+c-'0',c=this->next();
    nr*=semn;
}
template<class T,typename ... Args>
void input_parser::read(T & t,Args&...args){
    read(t);
    read(args...);
}

void input_parser::read(char *chp,size_t sz){
    char c;
    c=next();
    while(c==' ' || c=='\n')
        c=next();
    for(size_t i=0;i<sz && c!=' ' && c!='\n';i++)
        chp[i]=c,c=next();
}