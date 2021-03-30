

#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H
using namespace std;


#include "ast.h"

class PostFixVisitor: public ASTvisitor {
    public:


    virtual void visit(FileASTnode& node)
    {
        cout << "File started\n";
        if(node.getspec())
            node.getspec()->accept(*this);
        if(node.getmain())
            node.getmain()->accept(*this);
        cout << "File ended\n";
    }

    virtual void visit(Main_funcASTnode& node)
    {
        cout << "main_func started\n";
        if(node.getty())
            node.getty()->accept(*this);
        if(node.getstatelis())
            node.getstatelis()->accept(*this);
        cout << "main_func ended\n";
    }

    virtual void visit(TypeASTnode& node)
    {
        cout << "type started\n";
        cout << node.getstrin() << " ";

        cout << "type ended\n";
    }

    virtual void visit(Spec_funcASTnode& node)
    {
        cout << "spec_function started\n";
        if(node.gettyp())
            node.gettyp()->accept(*this);
        if(node.getfna())
            node.getfna()->accept(*this);
        if(node.getagm())
            node.getagm()->accept(*this);
        if(node.getstlis())
            node.getstlis()->accept(*this);
        cout << "spec_function ended\n";
    }

    virtual void visit(FnameASTnode& node)
    {
        cout << "Fname started\n";
        cout << node.getid() << " ";

        cout << "Fname ended\n";
    }

    virtual void visit(ArgumentsASTnode& node)
    {
        cout << "arguments started\n";
        if(node.getnagm())
            node.getnagm()->accept(*this);
        cout << "arguments ended\n";
    }

    virtual void visit(NargumentASTnode& node)
    {
    cout << "nargument started\n";
    vector <ASTnode*> rg = node.getag();
    for(int i=0;i<rg.size();i++){
        cout << "<nargument start>" <<"\n";
        cout << rg.size() <<"\n";
        rg[i]->accept(*this);
        cout <<"<nargument end>\n";
    }
    cout <<"nargument ended\n";
    }

    virtual void visit(ArgASTnode& node)
    {
      cout << "arg started\n";
      if(node.gettpe())
          node.gettpe()->accept(*this);
      if(node.gete1())
          node.gete1()->accept(*this);
      if(node.gete2())
          node.gete2()->accept(*this);
      cout << node.getid() << " ";
      cout << "arg ended\n";
    }

    virtual void visit(Statement_listASTnode& node)
    {
        cout << "statements list started\n";
        if(node.getdecl())
            node.getdecl()->accept(*this);
        if(node.getst())
            node.getst()->accept(*this);
        cout << "statements list ended\n";
    }

    virtual void visit(DeclarationASTnode& node)
    {
    cout << "Declaration started\n";
    vector <ASTnode*> temp = node.getdecla();
    for(int i=0;i<temp.size();i++){
        cout << "<Decl_start>" <<"\n";
        cout << temp.size() <<"\n";
        temp[i]->accept(*this);
        cout <<"<Decl_end>\n";
    }
    cout <<"end\n";
  }

  virtual void visit(D_stateASTnode& node)
  {
      cout << "D_state started\n";
      if(node.getty())
          node.getty()->accept(*this);
      if(node.getstatelis())
          node.getstatelis()->accept(*this);
      cout << "D_state ended\n";
  }

  virtual void visit(WordASTnode& node)
  {
      cout << "words started\n";
      vector <ASTnode*> temp = node.getlist();
      for(int i=0;i<temp.size();i++){
          cout << "<words start>" <<"\n";
          cout << temp.size() <<"\n";
          temp[i]->accept(*this);
          cout <<"<words end>\n";
      }
      cout <<"end\n";
  }

  virtual void visit(VarASTnode& node)
  {
    cout << "var started";
    if(node.gete1())
        node.gete1()->accept(*this);
    if(node.gete2())
        node.gete2()->accept(*this);
    cout << node.getid() << " ";
    cout << "var ended\n";
  }

  virtual void visit(StatementsASTnode& node)
  {
    cout << "statements started\n";
    if(node.gete1())
        node.gete1()->accept(*this);
    vector <ASTnode*> temp = node.getlist();
    for(int i=0;i<temp.size();i++){
        cout << "statements start" <<"\n";
        temp[i]->accept(*this);
        cout <<"statements end\n";
    }
    cout <<"end\n";
  }

  virtual void visit(VARIABLEASTnode& node)
  {
    cout << "variable started\n";
    if(node.gete1())
        node.gete1()->accept(*this);
    if(node.gete2())
        node.gete2()->accept(*this);
    cout << node.getid() << " ";
    cout << "varriable ended\n";
  }

  virtual void visit(ForconASTnode& node)
  {
    cout << "forcon started\n";
    cout << node.getid() << " ";
    cout << "forcon ended\n";
  }

  virtual void visit(ForendASTnode& node)
  {
    cout << "forend started";
    cout << node.getid() << " ";
    cout << "forend ended\n";
  }

  virtual void visit(ForloopASTnode& node)
  {
    cout << "forloop started";
    if(node.getfco())
        node.getfco()->accept(*this);
    if(node.getfen())
        node.getfen()->accept(*this);
    if(node.getstm())
        node.getstm()->accept(*this);
    cout << node.getid() << " ";
    cout << "forloop ended\n";
  }

  virtual void visit(WhileloopASTnode& node)
  {
      cout << "Whileloop started\n";
      if(node.getnagm())
          node.getnagm()->accept(*this);
      if(node.getnagm1())
          node.getnagm1()->accept(*this);
      cout << "Whileloop ended\n";
  }

  virtual void visit(ConditionASTnode& node)
  {
    cout << "condition started";
    if(node.gets1())
        node.gets1()->accept(*this);
    if(node.gets2())
        node.gets2()->accept(*this);
    if(node.gets3())
        node.gets3()->accept(*this);
    if(node.gets4())
        node.gets4()->accept(*this);
    if(node.gets5())
        node.gets5()->accept(*this);
    cout << "<condition ended\n";
  }
  virtual void visit(PrintASTnode& node)
  {
    cout << "print started";
    cout << node.getString() << " ";
    if(node.getnagm())
        node.getnagm()->accept(*this);
    cout << "print ended\n";
  }

  virtual void visit(ScanASTnode& node)
  {
      cout << "scanning started\n";
      if(node.getnagm())
          node.getnagm()->accept(*this);
      cout << "scanning ended\n";
  }

  virtual void visit(StmtASTnode& node)
  {
    cout << "lines started\n";
    vector <ASTnode*> temp = node.getlist();
    for(int i=0;i<temp.size();i++){
        cout << "lines start" <<"\n";
        temp[i]->accept(*this);
        cout <<"lines end\n";
    }
    cout <<"end\n";
  }
  virtual void visit(ExpressionASTnode& node)
  {
      cout << "expression started";
      if (node.gete1())
        node.gete1()->accept(*this);
      if (node.gete2())
        node.gete2()->accept(*this);
      if (node.gete3())
        node.gete3()->accept(*this);
      cout << "expression ended\n";
  }

  virtual void visit(BinaryASTnode& node)
  {
    node.getLeft()->accept(*this);
    node.getRight()->accept(*this);
    cout << node.getBinOperator() << " ";
  }


};

#endif /* POSTFIXVISITOR_H */
