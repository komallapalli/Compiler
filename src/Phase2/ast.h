
#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

using namespace std;


class BinaryASTnode;
class FileASTnode;
class Main_funcASTnode;
class TypeASTnode;
class Spec_funcASTnode;
class FnameASTnode;
class ArgumentsASTnode;
class NargumentASTnode;
class ArgASTnode;
class Statement_listASTnode;
class DeclarationASTnode;
class D_stateASTnode;
class WordASTnode;
class VarASTnode;
class VARIABLEASTnode;
class StatementsASTnode;
class ForconASTnode;
class ForendASTnode;
class ForloopASTnode;
class WhileloopASTnode;
class ConditionASTnode;
class PrintASTnode;
class ScanASTnode;
class StmtASTnode;
class ExpressionASTnode;


class ASTvisitor {
  public:
    virtual void visit(BinaryASTnode& node) = 0;
    virtual void visit(FileASTnode& node) = 0;
    virtual void visit(Main_funcASTnode& node) = 0;
    virtual void visit(TypeASTnode& node) = 0;
    virtual void visit(Spec_funcASTnode& node) = 0;
    virtual void visit(FnameASTnode& node) = 0;
    virtual void visit(ArgumentsASTnode& node) = 0;
    virtual void visit(NargumentASTnode& node) = 0;
    virtual void visit(ArgASTnode& node) = 0;
    virtual void visit(Statement_listASTnode& node) = 0;
    virtual void visit(DeclarationASTnode& node) = 0;
    virtual void visit(D_stateASTnode& node) = 0;
    virtual void visit(WordASTnode& node) = 0;
    virtual void visit(VarASTnode& node) = 0;
    virtual void visit(StatementsASTnode& node) = 0;
    virtual void visit(VARIABLEASTnode& node) = 0;
    virtual void visit(ForconASTnode& node) = 0;
    virtual void visit(ForendASTnode& node) = 0;
    virtual void visit(ForloopASTnode& node) = 0;
    virtual void visit(WhileloopASTnode& node) = 0;
    virtual void visit(ConditionASTnode& node) = 0;
    virtual void visit(PrintASTnode& node) = 0;
    virtual void visit(ScanASTnode& node) = 0;
    virtual void visit(StmtASTnode& node) = 0;
    virtual void visit(ExpressionASTnode& node) = 0;
};

class ASTnode {
     public :
     virtual ~ASTnode()
     {
     }
     virtual void accept(ASTvisitor& V) = 0;

};

class FileASTnode : public ASTnode
{
    public:

    FileASTnode(ASTnode* mainfn){
        this->main = mainfn;
        this->spec = NULL;
    }

    FileASTnode(ASTnode* specfn,ASTnode* mainfn){
        this->spec = specfn;
        this->main = mainfn;

    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

    ASTnode* getspec()
    {
      return spec;
    }

    ASTnode* getmain(){
      return main;
    }

    private:
    ASTnode* spec;
    ASTnode* main;
};


class Main_funcASTnode : public ASTnode
{
    public:
    Main_funcASTnode (ASTnode* tpe, ASTnode* stlist) {
        this->ty = tpe;
        this->statelis = stlist;
    }

    ASTnode* getty() {
        return ty;
    }

    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }
    ASTnode* getstatelis() {
        return statelis;
    }


  private:
    ASTnode* ty;
    ASTnode* statelis;
};

class TypeASTnode : public ASTnode
{
    public:
    TypeASTnode(string in){
        this->strin = in;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
      }
    string getstrin(){
        return strin;
    }
    private:
      string strin;

};


class Spec_funcASTnode : public ASTnode
{
    public:

    Spec_funcASTnode(ASTnode* tpe,ASTnode* fam,ASTnode* agu,ASTnode* slis){
        this->typ = tpe;
        this->fna = fam;
        this->agm = agu;
        this->stlis = slis;

    }

    ASTnode* gettyp()
    {
      return typ;
    }

    ASTnode* getfna(){
      return fna;
    }

    ASTnode* getagm(){
      return agm;
    }

    ASTnode* getstlis(){
      return stlis;
    }


    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    private:
    ASTnode* typ;
    ASTnode* fna;
    ASTnode* agm;
    ASTnode* stlis;
};

class FnameASTnode : public ASTnode
{
    public:

    string getid(){
        return id;
    }

    FnameASTnode(string idf){
        this->id = idf;
    }

    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }

    private:
      string id;

};

class ArgumentsASTnode : public ASTnode
{
    public:
    ArgumentsASTnode (ASTnode* nagu) {
        this->nagm = nagu;
    }
    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }

    ASTnode* getnagm() {
        return nagm;
    }


  private:
    ASTnode* nagm;
};

class NargumentASTnode : public ASTnode
{
    public:
    NargumentASTnode (){

    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    void push_back(ASTnode *rg){
        ag.push_back(rg);
    }
    vector <ASTnode*> getag(){
        return ag;
    }


  private:
    vector <ASTnode*> ag;
};

class ArgASTnode : public ASTnode
{
    public:
    ArgASTnode (ASTnode* ty,string idf){
        this->tpe = ty;
        this->id = idf;
        this->e1 = NULL;
        this->e2 = NULL;
    }

    ArgASTnode (string idfs,ASTnode* ex1){
        this->tpe = NULL;
        this->e1 = ex1;
        this->e2 = NULL;
        this->id = idfs;
    }

    ArgASTnode (string idfs,ASTnode* ex1,ASTnode* ex2){
        this->tpe = NULL;
        this->e1 = ex1;
        this->e2 = ex2;
        this->id = idfs;
    }

    ASTnode* gettpe() {
        return tpe;
    }

    ASTnode* gete1() {
        return e1;
    }
    ASTnode* gete2() {
        return e2;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

    string getid()
    {
        return id;
    }



  private:
    ASTnode* tpe;
    ASTnode* e1;
    ASTnode* e2;
    string id;
};

class Statement_listASTnode : public ASTnode
{
    public:
    Statement_listASTnode (ASTnode* dl,ASTnode* sts) {
        this->decl = dl;
        this->st = sts;
    }

    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }

    ASTnode* getdecl() {
        return decl;
    }

    ASTnode* getst() {
        return st;
    }



  private:
    ASTnode* decl;
    ASTnode* st;
};

class DeclarationASTnode : public ASTnode
{
    public:
    DeclarationASTnode (){

    }
    void push_back(ASTnode *temp){
        decla.push_back(temp);
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

    vector <ASTnode*> getdecla(){
        return decla;
    }

  private:
    vector <ASTnode*> decla;
};

class D_stateASTnode : public ASTnode
{
    public:
    D_stateASTnode (ASTnode* tpe, ASTnode* stlist) {
        this->ty = tpe;
        this->statelis = stlist;
    }
    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }
    ASTnode* getty() {
        return ty;
    }

    ASTnode* getstatelis() {
        return statelis;
    }



  private:
    ASTnode* ty;
    ASTnode* statelis;
};

class WordASTnode : public ASTnode
{
    public:
    WordASTnode (){

    }

    vector <ASTnode*> getlist(){
        return var;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    void push_back(ASTnode *temp){
        var.push_back(temp);
    }


  private:
    vector <ASTnode*> var;
};

class VarASTnode : public ASTnode
{
    public:
      ASTnode* gete1() {
          return e1;
      }
      ASTnode* gete2() {
          return e2;
      }
    VarASTnode (string idf,ASTnode* ex1){
        this->id = idf;
        this->e1 = ex1;
        this->e2 = NULL;
    }

    VarASTnode (string idfs){
        this->e1 = NULL;
        this->e2 = NULL;
        this->id = idfs;
    }

    string getid()
    {
        return id;
    }

    VarASTnode (string idfs,ASTnode* ex1,ASTnode* ex2){
        this->e1 = ex1;
        this->e2 = ex2;
        this->id = idfs;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* e1;
    ASTnode* e2;
    string id;
    string id1;
};

class StatementsASTnode : public ASTnode
{
    public:
    StatementsASTnode () {

    }
    StatementsASTnode (ASTnode* ex1) {
      this->e1 = ex1;
    }

    ASTnode* gete1() {
        return e1;
    }
    vector  <ASTnode*> getlist(){
        return stmnts;
    }
    void push_back(ASTnode *temp)
    {
        stmnts.push_back(temp);
        return;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> stmnts;
    ASTnode* e1;
};




class VARIABLEASTnode : public ASTnode
{
    public:
    VARIABLEASTnode (string idf,ASTnode* ex1){
        this->id = idf;
        this->e1 = ex1;
        this->e2 = NULL;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    VARIABLEASTnode (string idfs){
        this->e1 = NULL;
        this->e2 = NULL;
        this->id = idfs;
    }

    VARIABLEASTnode (string idfs,ASTnode* ex1,ASTnode* ex2){
        this->e1 = ex1;
        this->e2 = ex2;
        this->id = idfs;
    }

    ASTnode* gete1() {
        return e1;
    }
    ASTnode* gete2() {
        return e2;
    }

    string getid()
    {
        return id;
    }

  private:
    ASTnode* e1;
    ASTnode* e2;
    string id;
};

class ForconASTnode : public ASTnode
{
    public:
    ForconASTnode(){
    }

    string getid()
    {
        return id;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    string id;
};

class ForendASTnode : public ASTnode
{
    public:
    ForendASTnode(){
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    string getid()
    {
        return id;
    }

  private:
    string id;
};

class ForloopASTnode : public ASTnode
{
    public:


    ASTnode* getfco() {
        return fco;
    }

    ASTnode* getfen() {
        return fen;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    ASTnode* getstm() {
        return stm;
    }

    string getid()
    {
        return id;
    }
    ForloopASTnode (string idf,ASTnode* fcn,string idn,ASTnode* fed,string ide,ASTnode* slis){
        this->id = idf;
        this->fco = fcn;
        this->fen = fed;
        this->stm = slis;

    }

  private:
    ASTnode* fco;
    ASTnode* fen;
    ASTnode* stm;
    string id;
};

class WhileloopASTnode : public ASTnode
{
    public:
    ASTnode* getnagm() {
        return nagm;
    }
    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }
    ASTnode* getnagm1() {
        return nagm1;
    }
    WhileloopASTnode (ASTnode* nagu,ASTnode* nagu1) {
        this->nagm = nagu;
        this->nagm1 = nagu1;
    }

  private:
    ASTnode* nagm;
    ASTnode* nagm1;
};

class ConditionASTnode : public ASTnode
{
    public:


    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

    ASTnode* gets1() {return s1;}
    ASTnode* gets2(){return s2;}
    ASTnode* gets3(){return s3;}
    ASTnode* gets4(){return s4;}
    ASTnode* gets5(){return s5;}
    ConditionASTnode(ASTnode* st1,ASTnode* st2){
      this->s1 =st1;
      this->s2 = st2;
      this->s3 = NULL;
      this->s4 = NULL;
      this->s5 = NULL;
    }
    ConditionASTnode(ASTnode* st1,ASTnode* st2,ASTnode* st3){
      this->s1 =st1;
      this->s2 = st2;
      this->s3 = st3;
      this->s4 = NULL;
      this->s5 = NULL;
    }
    ConditionASTnode(ASTnode* st1,ASTnode* st2,ASTnode* st3,ASTnode* st4){
      this->s1 =st1;
      this->s2 = st2;
      this->s3 = st3;
      this->s4 = st4;
      this->s5 = NULL;
    }
    ConditionASTnode(ASTnode* st1,ASTnode* st2,ASTnode* st3,ASTnode* st4,ASTnode* st5){
      this->s1 =st1;
      this->s2 = st2;
      this->s3 = st3;
      this->s4 = st4;
      this->s5 = st5;
    }

    private:
    ASTnode* s1;
    ASTnode* s2;
    ASTnode* s3;
    ASTnode* s4;
    ASTnode* s5;
};

class PrintASTnode : public ASTnode
{
    public:
    PrintASTnode(){
    }
    PrintASTnode(string s1){
        this->str = s1;
    }
    PrintASTnode(ASTnode* nagu) {
        this->nagm = nagu;
    }
    string getString(){
        return str;
    }
    ASTnode* getnagm() {
        return nagm;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string str;
        ASTnode* nagm;
};

class ScanASTnode : public ASTnode
{
    public:
    ScanASTnode (ASTnode* nagu) {
        this->nagm = nagu;
    }

    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }

    ASTnode* getnagm() {
        return nagm;
    }

  private:
    ASTnode* nagm;
};

class StmtASTnode : public ASTnode
{
    public:
    StmtASTnode () {

    }
    void push_back(ASTnode *temp)
    {
        vardecls.push_back(temp);
        return;
    }
    vector  <ASTnode*> getlist(){
        return vardecls;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> vardecls;
};

class BinaryASTnode : public ASTnode
{
    public:
    // Constructor to initialize binary operator,
    // left node and right node of the binary expression.
    BinaryASTnode (string binOperatorParm,
                   ASTnode* pLeftParm,
                   ASTnode* pRightParm)
    :pLeft(pLeftParm)
    ,pRight(pRightParm)
    ,mBinaryOperator(binOperatorParm)
    {
    }

    /*  virtual void printPostFix() const
    {
    	lhs->printPostFix();
    	rhs->printPostFix();
    	std::cout << bin_operator << " ";
    } */

    ASTnode* getLeft()
    {
        return pLeft;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    ASTnode* getRight()
    {
        return pRight;
    }

    string getBinOperator()
    {
        return mBinaryOperator;
    }



  private:
    // left node and right node can be of any type.
    // So we need to use Base ASTnode type
    ASTnode* pLeft;
    ASTnode* pRight;
    string   mBinaryOperator;
};

class ExpressionASTnode : public ASTnode
{
    public:
    ExpressionASTnode (ASTnode* ex1){
        this->e1 = ex1;
        this->e2 = NULL;
        this->e3 = NULL;
    }

    ExpressionASTnode (ASTnode* ex2,ASTnode* ex3){
        this->e1 = NULL;
        this->e2 = ex2;
        this->e3 = ex3;
    }

    ExpressionASTnode (){
    }

    ASTnode* gete1() {
        return e1;
    }
    ASTnode* gete2() {
        return e2;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    ASTnode* gete3() {
        return e3;
    }


  private:
    ASTnode* e1;
    ASTnode* e2;
    ASTnode* e3;
};


class ASTContext
{
  public:
    ASTnode* pRoot;
    ~ASTContext()
    {
	    clearAST();
    }

    // free all saved expression trees
    void clearAST()
    {
        delete pRoot;
    }
};

#endif /* End of AST_H */
