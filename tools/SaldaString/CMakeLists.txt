# tools/SaldaString/CMakeLists.txt

# SaldaString kütüphanesini tanımla
add_library(SaldaString STATIC src/SaldaString.c)

# Kütüphane başlık dosyasını ekle
target_include_directories(SaldaString PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
