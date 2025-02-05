#include "Serializer.hpp"

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Test Data";


    std::cout << "Orijinal Data pointer: " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

    std::cout << "Deserialized Data id: " << deserializedData->id << std::endl;
    std::cout << "Deserialized Data name: " << deserializedData->name << std::endl;

    if (deserializedData == &myData) {
        std::cout << "Başarılı: Pointer'lar eşleşti!" << std::endl;
    } else {
        std::cout << "Hata: Pointer'lar eşleşmiyor!" << std::endl;
    }

    return 0;
}
