#include <string>

// Строковые константы для локализованного вывода
const std::string MSG_LOGO = (
        "                        _______________  ______________\n"
        "                        \\__    ___/\\   \\/  /\\__    ___/\n"
        "                          |    |    \\     /   |    |   \n"
        "                          |    |    /     \\   |    |   \n"
        "                          |____|   /___/\\  \\  |____|   \n"
        "                                         \\_/           \n"
        "                _____                .__    .__                    \n"
        "               /  _  \\_______   ____ |  |__ |__|__  __ ___________ \n"
        "              /  /_\\  \\_  __ \\_/ ___\\|  |  \\|  \\  \\/ // __ \\_  __ \\\n"
        "             /    |    \\  | \\/\\  \\___|   Y  \\  |\\   /\\  ___/|  | \\/\n"
        "             \\____|__  /__|    \\___  >___|  /__| \\_/  \\___  >__|   \n"
        "                     \\/            \\/     \\/              \\/       \n"
);
const std::string RU_MSG_MENU = (
        "Введите номер нужного пункта меню.\n"
        "1. Сжать файл.\n"
        "2. Разархивировать файл.\n"
        "3. Выход из программы."
);
const std::string EN_MSG_MENU = (
        "Enter the number of the desired menu item.\n"
        "1. Compress the file.\n"
        "2. Unzip the file.\n"
        "3. Exit the program."
);
const std::string RU_MSG_ENCODE = (
        "Введите номер нужного пункта меню.\n"
        "1. Сжать текст из файла.\n"
        "2. Сжать текст из консоли.\n"
        "3. Назад в меню."
);
const std::string EN_MSG_ENCODE = (
        "Enter the number of the desired menu item.\n"
        "1. Compress the text from the file.\n"
        "2. Compress the text from the console.\n"
        "3. Back to the menu."
);
const std::string RU_MSG_ENCODE_FILE = "Введите путь к файлу или его название.";
const std::string EN_MSG_ENCODE_FILE = "Enter the path to the file or its name.";
const std::string RU_MSG_ENCODE_CONSOLE = "Введите текст для архивации в консоль.";
const std::string EN_MSG_ENCODE_CONSOLE = "Enter the text to compress in the console.";
const std::string RU_MSG_DECODE = "Введите путь к файлу или его название (.txtarch).";
const std::string EN_MSG_DECODE = "Enter the path to the file or its name (.txtarch).";
const std::string RU_MSG_DECODE_ERROR = "ОШИБКА: Заархивированный файл должен иметь расширение .txtarch!\n";
const std::string EN_MSG_DECODE_ERROR = "ERROR: The archived file must have an extension .txtarch!\n";
const std::string RU_MSG_WRONG_INPUT = "Введите номер нужного пункта меню! (1-3).";
const std::string EN_MSG_WRONG_INPUT = "Enter the number of the desired menu item! (1-3).";
const std::string RU_MSG_WRONG_FORMAT = "ПРЕДУПРЕЖДЕНИЕ: Форматы файлов кроме .txt могут быть повреждены "
                                        "после разархивации!\n";
const std::string EN_MSG_WRONG_FORMAT = "WARNING: File formats other than .txt may be corrupted "
                                        "after unzipping!\n";
const std::string RU_MSG_BIGGER_FILE = "ПРЕДУПРЕЖДЕНИЕ: Сжатие может быть неэффективно ввиду малого размера или "
                                       "особенного формата файла!\n";
const std::string EN_MSG_BIGGER_FILE = "WARNING: Compression may not be effective due to the small size or "
                                       "a special file format!\n";
const std::string RU_MSG_FILE_SAVED = "Файл сохранён под названием ";
const std::string EN_MSG_FILE_SAVED = "File saved with name ";
const std::string RU_MSG_DECODE_CORRUPTED = "ПРЕДУПРЕЖДЕНИЕ: При разархивации файла возникли трудности, "
                                            "последний символ в файле может быть поверждён.\n";
const std::string EN_MSG_DECODE_CORRUPTED = "WARNING: There were difficulties when unzipping the file, "
                                            "the last character may be corrupted.\n";
const std::string RU_MSG_NO_FILE = "ОШИБКА: Файл с таким названием не найден.\n";
const std::string EN_MSG_NO_FILE = "ERROR: A file with this name was not found.\n";
const std::string RU_MSG_RATIO = "Степень сжатия: ";
const std::string EN_MSG_RATIO = "Compression ratio: ";
