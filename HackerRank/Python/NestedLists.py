if __name__ == '__main__':
    n = int(input())
    student = [[input(), float(input())] for i in range(n)] 
    student.sort(key = lambda x:x[1])  # sorts in ascending order
    minimum = student[0][1]  # Takes the minimum value
    l = [[student[i][0],student[i][1]] for i in range(n) if student[i][1] != minimum]
    j = [l[i][0] for i in range(len(l)) if l[i][1] == l[0][1]]  # It takes only minimum values
    j.sort()
    for i in range(len(j)):
        print(j[i], end = '\n')
