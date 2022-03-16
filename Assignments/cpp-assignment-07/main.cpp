#include "utilities.h"
#include "animal.h"
#include "Emoji.h"
#include "emoji_main.h"

int main() {
    // 1a
    // Public: Metoder og egenskaper som er tilgjengelig globalt for et object
    // Private: Metodet og egenskaper som kun er tilgjengelig i skopet for klassen de er deklarert i
    // Protected: Det samme som private, med unntak av at klasser som arver fra denne vil kunne benytte metodene og egenskapene.

    std::vector<std::unique_ptr<Animal>> animals;

    animals.emplace_back(new Dog("Odie", 9));
    animals.emplace_back(new Cat("Garfield", 11));
    animals.emplace_back(new Dog("Laika", 65));

    for (auto &animal : animals) {
        std::cout << animal->animal_to_string() << std::endl;
    }

    print_emojis();
}