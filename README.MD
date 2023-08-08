# Parallel word count.
Подсчет статистики встречаемости слов в текстовых файлах.
Имена текстовых файлов передаются в качестве параметров запуска.
Для увеличения достоверности замеров времени увеличено количество тестовых прогонов.
Задается в переменной iteration_count. По умолчанию 10.
Сначала исполняется последовательный алгоритм, затем параллельный.
Выводятся результаты последнего прогона. Время всех прогонов и среднее время.
После окончания работы алгоритмов проводится проверка выходных данных на состояние гонки.

### Пример входных параметров:
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\1.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\2.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\3.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\4.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\5.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\6.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\7.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\8.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\9.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\10.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\11.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\12.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\13.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\14.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\15.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\16.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\17.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\18.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\19.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\20.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\21.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\22.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\23.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\24.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\25.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\26.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\27.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\28.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\29.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\30.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\31.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\32.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\33.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\34.TXT
<your_path>\parallel_count\test_dataset\russ\parallel_count\test_dataset\russ\35.TXT

