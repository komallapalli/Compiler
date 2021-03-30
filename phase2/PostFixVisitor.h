

#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H

#include "ast.h"

class PostFixVisitor: public ASTvisitor {
    public:


    virtual void visit(FileASTnode& node)
    {
        std::cout << "File started\n";
        if(node.getspec())
            node.getspec()->accept(*this);
        if(node.getmain())
            node.getmain()->accept(*this);
        std::cout << "File ended\n";
    }

    virtual void visit(Main_funcASTnode& node)
    {
        std::cout << "main_func started\n";
        if(node.getty())
            node.getty()->accept(*this);
        if(node.getstatelis())
            node.getstatelis()->accept(*this);
        std::cout << "main_func ended\n";
    }

    virtual void visit(TypeASTnode& node)
    {
        std::cout << "type started\n";
        std::cout << node.getstrin() << " ";

        std::cout << "type ended\n";
    }

    virtual void visit(Spec_funcASTnode& node)
    {
        std::cout << "spec_function started\n";
        if(node.gettyp())
            node.gettyp()->accept(*this);
        if(node.getfna())
            node.getfna()->accept(*this);
        if(node.getagm())
            node.getagm()->accept(*this);
        if(node.getstlis())
            node.getstlis()->accept(*this);
        std::cout << "spec_function ended\n";
    }

    virtual void visit(FnameASTnode& node)
    {
        std::cout << "Fname started\n";
        std::cout << node.getid() << " ";

        std::cout << "Fname ended\n";
    }

    virtual void visit(ArgumentsASTnode& node)
    {
        std::cout << "arguments started\n";
        if(node.getnagm())
            node.getnagm()->accept(*this);
        std::cout << "arguments ended\n";
    }

    virtual void visit(NargumentASTnode& node)
    {
    std::cout << "nargument started\n";
    vector <ASTnode*> rg = node.getag();
    for(int i=0;i<rg.size();i++){
        std::cout << "<nargumentstart>" <<"\n";
        std::cout << rg.size() <<"\n";
        rg[i]->accept(*this);
        std::cout <<"<nargumentstart>\n";
    }
    std::cout <<"nargument end\n";
    }

    virtual void visit(ArgASTnode& node)
    {
      std::cout << "<arg>";
      if(node.gettpe())
          node.gettpe()->accept(*this);
      if(node.gete1())
          node.gete1()->accept(*this);
      if(node.gete2())
          node.gete2()->accept(*this);
      std::cout << node.getid() << " ";
      std::cout << "</arg>\n";
    }

    virtual void visit(Statement_listASTnode& node)
    {
        std::cout << "statements list started\n";
        if(node.getdecl())
            node.getdecl()->accept(*this);
        if(node.getst())
            node.getst()->accept(*this);
        std::cout << "statements list ended\n";
    }

    virtual void visit(DeclarationASTnode& node)
    {
    std::cout << "Declaration started\n";
    vector <ASTnode*> temp = node.getdecla();
    for(int i=0;i<temp.size();i++){
        std::cout << "<methodstart>" <<"\n";
        std::cout << temp.size() <<"\n";
        temp[i]->accept(*this);
        std::cout <<"<Declarationend>\n";
    }
    std::cout <<"end\n";
  }

  virtual void visit(D_stateASTnode& node)
  {
      std::cout << "D_state started\n";
      if(node.getty())
          node.getty()->accept(*this);
      if(node.getstatelis())
          node.getstatelis()->accept(*this);
      std::cout << "D_state ended\n";
  }

  virtual void visit(WordASTnode& node)
  {
      std::cout << "words started\n";
      vector <ASTnode*> temp = node.getlist();
      for(int i=0;i<temp.size();i++){
          std::cout << "<words start>" <<"\n";
          std::cout << temp.size() <<"\n";
          temp[i]->accept(*this);
          std::cout <<"<wordss end>\n";
      }
      std::cout <<"end\n";
  }

  virtual void visit(VarASTnode& node)
  {
    std::cout << "<var>";
    if(node.gete1())
        node.gete1()->accept(*this);
    if(node.gete2())
        node.gete2()->accept(*this);
    std::cout << node.getid() << " ";
    std::cout << "</var>\n";
  }

  virtual void visit(StatementsASTnode& node)
  {
    std::cout << "statements started\n";
    if(node.gete1())
        node.gete1()->accept(*this);
    vector <ASTnode*> temp = node.getlist();
    for(int i=0;i<temp.size();i++){
        std::cout << "statements start" <<"\n";
        temp[i]->accept(*this);
        std::cout <<"statements end\n";
    }
    std::cout <<"end\n";
  }

  virtual void visit(VARIABLEASTnode& node)
  {
    std::cout << "<variable started>";
    if(node.gete1())
        node.gete1()->accept(*this);
    if(node.gete2())
        node.gete2()->accept(*this);
    std::cout << node.getid() << " ";
    std::cout << "</varriable ended>\n";
  }

  virtual void visit(ForconASTnode& node)
  {
    std::cout << "<forcon>";
    std::cout << node.getid() << " ";
    std::cout << "</forcon>\n";
  }

  virtual void visit(ForendASTnode& node)
  {
    std::cout << "<forendr>";
    std::cout << node.getid() << " ";
    std::cout << "</forend>\n";
  }

  virtual void visit(ForloopASTnode& node)
  {
    std::cout << "<forloop>";
    if(node.getfco())
        node.getfco()->accept(*this);
    if(node.getfen())
        node.getfen()->accept(*this);
    if(node.getstm())
        node.getstm()->accept(*this);
    std::cout << node.getid() << " ";
    std::cout << "</forloop>\n";
  }

  virtual void visit(WhileloopASTnode& node)
  {
      std::cout << "Whileloop started\n";
      if(node.getnagm())
          node.getnagm()->accept(*this);
      if(node.getnagm1())
          node.getnagm1()->accept(*this);
      std::cout << "Whileloop ended\n";
  }

  virtual void visit(ConditionASTnode& node)
  {
    std::cout << "<condition starts>";
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
    std::cout << "<condition ends>\n";
  }
  virtual void visit(PrintASTnode& node)
  {
    std::cout << "<print starts>";
    std::cout << node.getString() << " ";
    std::cout << "<print ends>1\n";
  }
  virtual void visit(ScanASTnode& node)
  {
    std::cout << "<scanning starts>";
    std::cout << node.getString() << " ";
    std::cout << "<scanning ends>1\n";
  }
  virtual void visit(StmtASTnode& node)
  {
    std::cout << "lines started\n";
    vector <ASTnode*> temp = node.getlist();
    for(int i=0;i<temp.size();i++){
        std::cout << "lines start" <<"\n";
        temp[i]->accept(*this);
        std::cout <<"lines end\n";
    }
    std::cout <<"end\n";
  }
  virtual void visit(ExpressionASTnode& node)
  {
      std::cout << "<expression starts>";
      if (node.gete1())
        node.gete1()->accept(*this);
      if (node.gete2())
        node.gete2()->accept(*this);
      if (node.gete3())
        node.gete3()->accept(*this);
      std::cout << "<expression ends>\n";
  }

  virtual void visit(BinaryASTnode& node)
  {
    node.getLeft()->accept(*this);
    node.getRight()->accept(*this);
    std::cout << node.getBinOperator() << " ";
  }


};

#endif /* POSTFIXVISITOR_H */
