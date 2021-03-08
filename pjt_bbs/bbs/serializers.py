from rest_framework import serializers  
from bbs.models import Bbs

class BbsSerializer(serializers.ModelSerializer):
    # ModelSerializer 를 이용해서 아래와 같이 짧은 코드로 직렬화 필드를 정의할 수 있다
    class Meta:
        model = Bbs
        fields = ('id','title','author','pw','content')

    # 신규 Bbs instance를 생성해서 리턴해준다
    def create(self, validated_data):
        return Bbs.objects.create(**validated_data)

    # 생성되어 있는 Bbs instance 를 저장한 후 리턴해준다
    def update(self, instance, validated_data):
        instance.title = validated_data.get('title', instance.title)
        instance.author = validated_data.get('author', instance.author)
        instance.pw = validated_data.get('pw', instance.pw)
        instance.content = validated_data.get('content', instance.content)
        instance.save()
        return instance