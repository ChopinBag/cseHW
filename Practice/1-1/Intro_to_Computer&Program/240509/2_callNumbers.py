print('--------------------')
print('1. 친구 리스트 출력')
print('2. 친구 추가')
print('3. 친구 삭제')
print('4. 이름 변경')
print('9. 종료')
selectedMenu = int(input('메뉴를 선택하시오: '))
print('--------------------')

friends = []

def menu(num): 
    if num == 1:
        print(friends)
    elif num == 2:
        friends.append(str(input('이름을 입력하시오: ')))
        
    elif num == 3:
        name = str(input('이름을 입력하시오: '))
        if friends == []:
            print('친구목록이 없습니다')
        while name not in friends:
            name = str(input('이름을 다시 입력하시오: '))
        friends.remove(name)

    elif num == 4:
        oldName = str(input('변경할 이름을 입력하시오: '))
        if oldName not in friends:
            print('변경할 이름이 존재하지 않습니다.')
        else:
            newName = str(input('새로운 이름을 입력하시오: '))
            friends[friends.index(oldName)] = newName
    elif num == 9:
        return 0
    else:
        print('메뉴에 등록된 숫자를 입력하시오')
    
