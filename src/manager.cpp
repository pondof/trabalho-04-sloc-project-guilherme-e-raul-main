#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
// ok

void help (void) {
std::cout<< "Welcome to slocpp, version 1.0, (c) 2024 Selan, DIMAp, UFRN.\n";
std::cout<< "Usage: sloc [options] file/directory\n";
std::cout<< "Options: \n";
std::cout<< "  -h/--help       Display this information.\n";
std::cout<< "  -r              Look for files recursively in the directory provided.\n";
std::cout<< "  -s f/t/c/b/s/a  Sort table in ascending order by (f)ilename, (t) filetype,\n";
std::cout<< "                  (c)omments, (b)lank lines, (s)loc, or (a)ll. Default is to show\n";
std::cout<< "                  files in ordem of appearance.\n";
std::cout<< "  -S f/t/c/b/s/a  Same as above, but in descending order.\n";
}


while(archive.good()) { 
    std::string character;
    char line = std::getline(archive, character);

    if (blank() == false) {
        for (int i=0;i<line.length();i++) {
            if  (line[i] == '/' && line[i+1]== '/') { // comentario //
                cont_comentarios+=1;
            } 
            if  (line[i] == '/' && line[i+1]== '*') { // comentario /*
                cont_comentarios+=1;
            } 
            if  (line[i] == '\t' && line[i+1]== '*') { // comentario *
                cont_comentarios+=1;
            }
            if  (line[i] == '*' && line[i+1]== '/') { // comentario */
                cont_comentarios+=1;
            }
            /*
            else if (isblank(line)==0){ // se tiver em branco
            cont_blank++;
            } 
            */
            else { // o que nao for comentario nem tiver em branco e codigo
                cont_code++;
            }
            cont_linha++;
        }
    }
}


// realmente checar se a linha esta em branco e pode ser usada na outra funcao, se essa funcao  retornar falsa
// checar se e comentario ou nao. 
// funcao blank.
void blank() {
    
    std::string character;
    while (getline(archive, character)) {
        bool blank = true;
        for (char line : character) {
            if (!std::isspace(static_cast<unsigned char>(line))) { // se nao for vazio vai retornar falso 
                blank = false;
                return false;
                break;
            
            }
        } 
        if  (blank) { // se for vazio soma linhas em branco 
            cont_blank++;
        }

    }   
    return cont_blank++;
}
//loop para fazer o calculo todo
while (true) {
    

}