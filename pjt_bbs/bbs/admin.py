from django.contrib import admin
from .models import Bbs

class BbsAdmin(admin.ModelAdmin):
    list_display=('title','author','created',)

admin.site.register(Bbs, BbsAdmin)