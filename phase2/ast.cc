// $Id$

#include <iostream>
#include <fstream>
#include "driver.h"
#include "ast.h"
#include "PostFixVisitor.h"


int main()
{
    ASTContext ast;
    decaf::Driver driver(ast);
    PostFixVisitor pfv;

    string line;
    while( cout << "input: " &&
	   getline(cin, line) &&
	   !line.empty() )
    {

	    bool result = driver.parse_string(line, "input");

	    if (result)
    	{
            if (ast.pRoot != NULL ) {
                FileASTnode *pnode;
                cout << "AST started" << endl;

                pnode = dynamic_cast<FileASTnode *>(ast.pRoot);
                if (pnode != NULL)
                    pfv.visit(*pnode);

                 cout <<  endl;
            }
            ast.clearAST();
	    }
	}
}
