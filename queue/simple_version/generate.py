import random  
import string  
  
def generate_student_info(num_students):  
    student_infos = []  
    for _ in range(num_students):  
        # 生成8位学号  
        student_id = ''.join(random.choices(string.digits, k=8))  
          
        # 生成10位以内的姓名  
        first_name_length = random.randint(5, 10)  
        first_name = ''.join(random.choices(string.ascii_letters, k=first_name_length))  
          
        # 生成随机成绩和用时  
        score = random.randint(47, 100)  # 假设成绩范围在0到1000之间  
        time_taken = random.randint(45, 100)  # 假设用时范围在1到500之间  
          
        # 将学生信息添加到列表中  
        student_infos.append(f"{student_id} {first_name} {score} {time_taken}")  
      
    return student_infos  
  
# 生成1000条学生信息  
num_students = 50
student_infos = generate_student_info(num_students)  
  
# 打印或保存学生信息  
# 打印前几条作为示例（避免打印全部信息导致过长）  
for i in range(10):  # 可以调整打印的数量  
    print(student_infos[i])  
  
# 如果需要保存到文件，可以使用以下代码  
with open("data.txt", "w") as file:  
    for info in student_infos:  
        file.write(info + "\n")