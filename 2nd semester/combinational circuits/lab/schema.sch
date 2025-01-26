<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="inp" />
        <signal name="outp" />
        <port polarity="Input" name="inp" />
        <port polarity="Output" name="outp" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="obuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
        </blockdef>
        <blockdef name="ibuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <block symbolname="inv" name="XLXI_1">
            <blockpin signalname="XLXN_2" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="I" />
            <blockpin signalname="outp" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_4">
            <blockpin signalname="inp" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1568" y="1280" name="XLXI_1" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1824" y1="1248" y2="1248" x1="1792" />
        </branch>
        <instance x="1824" y="1280" name="XLXI_3" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="1568" y1="1248" y2="1248" x1="1536" />
        </branch>
        <instance x="1312" y="1280" name="XLXI_4" orien="R0" />
        <branch name="inp">
            <wire x2="1312" y1="1248" y2="1248" x1="1280" />
        </branch>
        <iomarker fontsize="28" x="1280" y="1248" name="inp" orien="R180" />
        <branch name="outp">
            <wire x2="2080" y1="1248" y2="1248" x1="2048" />
        </branch>
        <iomarker fontsize="28" x="2080" y="1248" name="outp" orien="R0" />
    </sheet>
</drawing>