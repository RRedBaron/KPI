from abc import ABC, abstractmethod

DAYS = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


class TDate(ABC):
    day = 1
    month = 1
    year = 1

    def __init__(self, line: str):
        symbols = ['.', '-', ':', ',', ';']
        for i in line:
            if i in symbols:
                line = line.replace(i, ' ')
        line = line.split()
        self.day = int(line[0])
        self.month = int(line[1])
        self.year = int(line[2])

    def increase_date(self, day=0, month=0, year=0):
        while day != 0:
            self.day += 1
            if self.day > DAYS[self.month - 1]:
                self.day = 1
                self.month += 1
                if self.month > 12:
                    self.year += 1
                    self.month = 1
            day -= 1
        while month != 0:
            self.month += 1
            if self.month > 12:
                self.year += 1
                self.month = 1
            month -= 1
        self.year += year

    def decrease_date(self, day=0, month=0, year=0):
        while day != 0:
            self.day -= 1
            if self.day == 0:
                self.month -= 1
                if self.month == 0:
                    self.year -= 1
                    self.month = 12
                self.day = DAYS[self.month-1]
            day -= 1
        while month != 0:
            self.month -= 1
            if self.month == 0:
                self.month = 12
                self.year -= 1
            month -= 1
        self.year -= year

    def is_in_time_interval(self, date1, date2):
        date1 = TDate1(date1).get_days_since_year_0()
        date2 = TDate1(date2).get_days_since_year_0()
        if date1 <= self.get_days_since_year_0() <= date2:
            return True

    def get_days_since_year_0(self):
        return self.year * 365 + self.month * 30 + self.day

    @abstractmethod
    def __str__(self):
        pass


class TDate1(TDate):

    def __str__(self):
        return f"{self.day}.{self.month}.{self.year}"


class TDate2(TDate):

    def __str__(self):
        return f"{self.day}-{self.month}-{self.year}"
