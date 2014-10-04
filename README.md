Jinn
====

Установка
---------

Системные требования:
1. Компилятор GCC 4.7 и выше или MSVC 2010 и выше
2. Qt 5.0 или выше
3. [QJS](https://github.com/maxvas/qjs)

**Установка на Unix из исходников:**

    git clone https://github.com/maxvas/jinn
    cd jinn
	qmake
	make install
	jinnd -i && jinnd
  
**Установка на Windows из исходников:**

	git clone https://github.com/maxvas/jinn
	cd jinn
	qmake
	nmake install
	
Далее необходимо добваить в переменную PATH путь до файла jinnd.exe, который лежит в "<jinn-src>\package\win32\build\jinnd.exe"
Кроме того, необходимо добваить системную переменную JINN с путем до "<jinn-src>\package\win32\bin"
После этого можно запускать сервер командой:
	
	jinnd -i && jinnd


Для проверки работоспособности сервера откройте в браузере страницу [http://localhost:8888/](http://localhost:8888/). Должна отобразиться надпись "Тестовый модуль".

