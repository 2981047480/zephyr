# -*- coding: utf-8 -*-
import scrapy
import re
from scrapy import Request


class BeikeSpider(scrapy.Spider):
    name = 'beike'
    allowed_domains = ['sh.zu.ke.com']
    start_urls = ['http://sh.zu.ke.com/']

    def parse(self, response):
        def insidepage():
            price1 = response.xpath('//div[contains(@class,"content__aside fr")]/p/span/text()').extract_first()
            price2 = response.xpath('//div[contains(@class,"content__aside fr")]/p/text()').extract()[1]
            price2=price2.replace('\n          ','')
            price2=price2.replace('        ',' ')
            price = str(price1) + str(price2)
            print(price1)
            print(price2)
            print(price)
            title1 = response.xpath('//div[contains(@class,"content clear")]/p/text()').extract_first()
            title=re.findall(r'租·(.*?) .*?',title1)
            title1=title1.replace('整租·','')
            title1=title1.replace('合租·','')
            #title2=title1.split(' ')
            print(title)
            load = response.xpath('//p[contains(@class,"content__aside--tags")]//i/text()').extract()
            print(load)
            id = response.xpath('//div[contains(@class,"content__subtitle")]/i[2]/text()').extract_first()
            id=id.strip('房源编号：')
            print(id)
            time = response.xpath('//div[contains(@class,"content__subtitle")]/text()').extract()
            time = time.pop(1)
            print(time)
            type = response.xpath('//p[@class="content__article__table"]/span[1]/text()').extract_first()
            print(type)
            huxing = response.xpath('//p[@class="content__article__table"]/span[2]/text()').extract_first()
            print(huxing)
            huxing=huxing.replace('室','室 ')
            huxing=huxing.replace('厅', '厅 ')
            huxing=huxing.replace('卫', '卫 ')
            area = response.xpath('//p[@class="content__article__table"]/span[3]/text()').extract_first()
            print(area)
            toward = response.xpath('//p[@class="content__article__table"]/span[4]/text()').extract_first()
            toward=toward.replace('  ',' ')
            toward=toward.replace(' ','')
            toward=toward.replace('朝','')
            toward=toward.replace(' ','/')
            print(toward)
            ruzhu=response.xpath('//div[@class="content__article__info"]/ul/li[3]/text()').extract_first()
            ruzhu=ruzhu.split('入住：')
            zuqi = response.xpath('//div[@class="content__article__info"]/ul/li[5]/text()').extract_first()
            zuqi=zuqi.split('租期：')
            kanfang = response.xpath('//div[@class="content__article__info"]/ul/li[6]/text()').extract_first()
            kanfang=kanfang.strip('看房：')
            louceng = response.xpath('//div[@class="content__article__info"]/ul/li[8]/text()').extract_first()
            louceng=louceng.replace('楼层：','')
            louceng=louceng.replace('/',' ')
            dianti = response.xpath('//div[@class="content__article__info"]/ul/li[9]/text()').extract_first()
            dianti=dianti.split('电梯：')
            chewei = response.xpath('//div[@class="content__article__info"]/ul/li[11]/text()').extract_first()
            chewei=chewei.split('车位：')
            yongshui = response.xpath('//div[@class="content__article__info"]/ul/li[12]/text()').extract_first()
            yongshui=yongshui.split('用水：')
            yongdian = response.xpath('//div[@class="content__article__info"]/ul/li[14]/text()').extract_first()
            yongdian=yongdian.split('用电：')
            ranqi = response.xpath('//div[@class="content__article__info"]/ul/li[15]/text()').extract_first()
            ranqi=ranqi.split('燃气：')
            cainuan=response.xpath('//div[@class="content__article__info"]/ul/li[17]/text()').extract_first()
            cainuan=cainuan.split('采暖：')
            local = response.xpath('//div[contains(@class,"bread__nav w1150 bread__nav--bottom")]/p/a/text()').extract()
            print(local)
            local2 = []
            list=[]
            list.append(id)
            for local1 in local:
                local1 = local1.replace('租房网',' ')
                local1=local1.replace('贝壳网',' ')
                local1 = local1.replace('租房',' ')
                local1 = local1.replace('网',' ')
                local2.append(local1)
            print(local2)
            list.append(local2)
            list.append(title)
            list.append(area)
            list.append(type)
            list.append(toward)
            if ('付价' in price):
                list.append(price)
            else:
                price = price + ' NULL'
                list.append(price)
            list.append(huxing)
            list.append(ruzhu)
            list.append(zuqi)
            list.append(kanfang)
            list.append(louceng)
            list.append(dianti)
            list.append(chewei)
            list.append(yongshui)
            list.append(yongdian)
            list.append(ranqi)
            list.append(cainuan)
            #list.append(load)
            #list.append(time)
            #list.append(list1)
            item={"price":price,"title":title,"location":load,"id":id,"time":time,"户型":huxing,"地方":area,"房屋朝向":toward,"地方":list}
            #yield item
            with open('房源信息.txt','a',encoding='utf-8') as fp:
                for item in list:
                    fp.writelines(item)
                    fp.write(' ')
                fp.write('\n')


        base_url = 'https://sh.zu.ke.com'
        if (response.url=='https://sh.zu.ke.com/zufang'):
            for href in response.xpath('//*[@id="content"]/div[1]/ul[2]/li/a/@href').extract():
                next_urls = str(base_url) + str(href)
                #print(next_url)
                yield Request(next_urls)
        elif('pg' in str(response.url)):
            #print(True)
            for inside_url in response.xpath('//div[contains(@class,"content__list--item")]/a/@href').extract():
                inside_urls = base_url + str(inside_url)
                print(inside_urls)
                yield Request(inside_urls)
        elif('SH' in str(response.url)):
            insidepage()
