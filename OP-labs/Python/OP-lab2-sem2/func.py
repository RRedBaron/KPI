import pickle


def is_client_in(client: dict, base: list):
    for i in base:
        start_time1 = int(client['start_time'].split(':')[0]) * 60 + int(client['start_time'].split(':')[1])
        end_time1 = int(client['end_time'].split(':')[0]) * 60 + int(client['end_time'].split(':')[1])
        if end_time1 < start_time1: end_time1 += 1440
        start_time2 = int(i['start_time'].split(':')[0]) * 60 + int(i['start_time'].split(':')[1])
        end_time2 = int(i['end_time'].split(':')[0]) * 60 + int(i['end_time'].split(':')[1])
        if end_time2 < start_time2: end_time2 += 1440
        if client['surname'] == i['surname']:
            return True
        elif end_time2 > end_time1 > start_time2:
            return True
        elif start_time1 < start_time2 and end_time1 > end_time2:
            return True
        elif start_time2 < start_time1 < end_time2:
            return True
        else:
            return False
    return False


def create_file(file_name):
    input_mode = int(input('''Выберите режим ввода информации:
    1)Дозапись в существующий(если существует файл с таким именем)
    2)Создать новый файл\n'''))
    while True:
        if input_mode == 1:
            break
        elif input_mode == 2:
            file = open(file_name, "wb").close()
            break
        else:
            input_mode = input("Введите 1 или 2")
    lst = []
    try:
        with open(file_name, "rb") as file:  # получение данных из файла для дозаписи
            lst = pickle.load(file)
    except:
        pass
    with open(file_name, "wb") as file:
        line = input('''Вводите информацию о клиенте в формате [Фамилия ЧЧ:ММ ЧЧ:ММ].
Чтобы остановить ввод, введите пустую строку.\n''').split()
        while (line):
            client = {
                'surname': line[0],
                'start_time': line[1],
                'end_time': line[2],
            }
            if not is_client_in(client, lst):
                lst.append(client)
            else:
                print("Ошибка!")
            line = input().split()
        pickle.dump(lst, file)


def create_new_file(file_name1, file_name2):
    # try:
    with open(file_name1, "rb") as inf:
        text = pickle.load(inf)
        new_text = []
        for i in range(len(text)):
            start_time = int(text[i]['start_time'].split(':')[0]) * 60 + int(text[i]['start_time'].split(':')[1])
            end_time = int(text[i]['end_time'].split(':')[0]) * 60 + int(text[i]['end_time'].split(':')[1])
            if end_time < start_time: end_time += 1440
            if (end_time - start_time) > 30:
                new_text.append(text[i])
        with open(file_name2, "wb") as ouf:
            pickle.dump(new_text, ouf)


def print_file(file_name):
    try:
        with open(file_name, "rb") as file:
            print(f"=====Содержимое {file_name}=====")
            text = pickle.load(file)
            for i in text:
                for values in i.values():
                    print(values, end=' ')
                print()
            print()
    except:
        print('Ошибка при открытии файла!')
