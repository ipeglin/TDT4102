#include "utilities.h"
#include "files.h"
#include "strings.h"
#include "course_catalog.h"
#include "temp.h"

int main() {

    // 2b
    // The [] operator is not supported for maps. Only arrays and vectors

    Course_catalog cc;
    cc.load_catalog();

    // 3d
    // insert() does not overwrite map values, but the [] operator does

    std::cout << "-------- COURSES --------" << std::endl
              << cc;

    
}