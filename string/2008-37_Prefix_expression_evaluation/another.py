expression = input().split()[::-1]  # 读入前缀表达式并反转顺序
stack = []

for x in expression:
    if x.isdigit():  # 如果当前字符是数字
        stack.append(int(x))  # 将其转换为整数并压入栈中
    else:  # 如果当前字符是操作符
        a = stack.pop()  # 弹出两个数字
        b = stack.pop()
        if x == "+":
            stack.append(a + b)  # 计算它们的值，并将结果压入栈中
        elif x == "-":
            stack.append(a - b)
        elif x == "*":
            stack.append(a * b)
        elif x == "/":
            stack.append(a / b)

print(stack[0])  # 栈中的唯一元素即为表达式的值
