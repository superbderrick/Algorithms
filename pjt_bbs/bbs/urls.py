from django.conf.urls import url
from rest_framework.urlpatterns import format_suffix_patterns  
from bbs import views

urlpatterns = [
    url(r'^$', views.bbs_list),
    url(r'^(?P<pk>[0-9]+)/$', views.bbs_detail),
]

urlpatterns = format_suffix_patterns(urlpatterns)