from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response
from bbs.models import Bbs  
from bbs.serializers import BbsSerializer

# 요청 url 인 bbs/ 에 대해서 urls.py 에 정의된 view.bbs_list 가 호출된다.
@api_view(['GET', 'POST'])
def bbs_list(request, format=None):  
    if request.method == 'GET':
        bbs = Bbs.objects.all()
        serializer = BbsSerializer(bbs, many=True) # many 값이 True 이면 다수의 데이터 instance를 직렬화할수 있다
        return Response(serializer.data)

    elif request.method == 'POST':
        serializer = BbsSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

# 요청 url 인 bbs/번호 에 대해서 urls.py 에 정의된 view.bbs_detail 이 호출된다
@api_view(['GET', 'PUT', 'DELETE'])
def bbs_detail(request, pk, format=None):
    try:
        bbs = Bbs.objects.get(pk=pk)
    except Bbs.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == 'GET':
        serializer = BbsSerializer(bbs)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = BbsSerializer(bbs, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        bbs.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)